#include <stdio.h>
#include <unistd.h>

int main(){
        printf("exec 이후\n");
        printf("pid : %d, ppid : %d\n",getpid(),getppid());
        return 0;
}
