#include "ProcessControl.h"

i32 AttachToProcess(pid_t pid)
{
    if(ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1)
    {
        perror("ptrace Attach");
        return 1;
    }
    return 0;
}
i32 OpenProcess(const char* programName)
{
    if(ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    {
        perror("ptrace Attach");
        return -1;
    }
    execl(programName, programName, (char*) NULL); 
    _exit(1);
}
i32 DetachProcess(pid_t pid)
{
    if(ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1)
    {
        perror("ptrace detach");
        return -1;
    }
    return 1;
}
