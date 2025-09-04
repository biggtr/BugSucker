cmake_minimum_required(VERSION 3.30)
project(BugSucker)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF) 
set(CMAKE_PCH_ENABLED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

if(WIN32)
    set(PLATFORM_NAME "Win")
elseif(UNIX)
    set(PLATFORM_NAME "Linux")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -DBIT_DEBUG -Wall -Wextra -fsanitize=address -fsanitize=undefined")
    set(CMAKE_CXX_FLAGS_RELEASE " -O3 -DNDEBUG -Wall")
endif()

add_executable(BugSucker)
target_sources(BugSucker
    PRIVATE
    src/Core/main.cpp
)

target_include_directories(BugSucker
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_compile_definitions(BugSucker
    PRIVATE
    $<$<CONFIG:Debug>:BSUCK_DEBUG=1>
)
target_link_libraries(BugSucker X11 ${CMAKE_THREAD_LIBS_INIT} OpenGL::GL)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(BugSucker
        PRIVATE -Wall -Wextra -Wpedantic 
        -Wno-unused-function -Wno-unused-parameter -Wno-pedantic 
    ) 
endif()

set_target_properties(BugSucker PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin-int/$<CONFIG>/${PLATFORM_NAME}"
    OUTPUT_NAME "BugSucker"  
)
