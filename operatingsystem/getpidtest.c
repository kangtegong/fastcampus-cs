#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, ppid;

    pid = getpid();   // Get the process ID
    ppid = getppid(); // Get the parent process ID

    printf("Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    return 0;
}
