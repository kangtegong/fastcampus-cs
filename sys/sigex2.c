#include<stdio.h>
#include<signal.h>
#include <unistd.h>

// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig)
{
    printf("Caught signal %d\n", sig);
}

int main()
{
    int timer = 5;
    signal(SIGINT, handle_sigint);

    while (timer > 0) {
        printf("main routine...%d\n", timer--);
	sleep(1);
    }
    return 0;
}
