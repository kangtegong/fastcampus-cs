#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int cnt = 5;

int main(){
    static struct sigaction act;
    void my_sighandle(int);

    act.sa_handler = my_sighandle;
    sigfillset(&(act.sa_mask));
    sigaction(SIGINT, &act, NULL);

    while(1)
    {
        printf("code is running...\n");
	sleep(1);
	if(cnt < 0)
	    exit(0);
    }

}

void my_sighandle(int signum){
    printf("terminate if you press Ctrl+C %d time(s) more...\n", cnt--);
}
