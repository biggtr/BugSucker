#include "Process/ProcessControl.h"

int main()
{

    pid_t child = fork();

    if(child == 0)
    {
        OpenProcess("./testProgram");
    }
    else if(child < 0)
    {
        perror("Failed to create Child");
    }
    else  
    {
        int status;
        waitpid(child, &status, 0);
        DetachProcess(child);
    }

    return 0;
}
