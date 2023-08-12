#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int count = 5;

    if((pid = fork()) > 0)
    {
        sleep(2);
	kill(pid, SIGINT);
	raise(SIGINT);
	printf("will this code executed?\n");
    }
    else if (pid == 0)
    {
        while(count) {
	     printf("child process countdown %d\n", count--);
	     sleep(1);
	}
    }
    else
    {
        printf("fork failed\n");
    }
    return 0;

}