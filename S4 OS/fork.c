#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork(); // Create a new process

    if(pid < 0)
    {
        perror("Fork failed");
        return 1;
    }
    else if(pid == 0)
    {
        // Child Process
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    }
    else
    {
        // Parent Process
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        sleep(5); // Keeps parent alive for observation
    }

    return 0;
}