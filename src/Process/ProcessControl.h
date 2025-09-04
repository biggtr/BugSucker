#pragma once 
#include "Core/Defines.h"
#include <sys/types.h>
#include "stdio.h"
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/wait.h>

i32 AttachToProcess(pid_t pid);
i32 OpenProcess(const char* programName);
i32 DetachProcess(pid_t pid);
