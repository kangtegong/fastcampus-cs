#include <unistd.h>
#include <stdio.h>

int main(){
        char *file = "process3";
        char *argv[] = {file, NULL};
        printf("exec 전\n");
        printf("pid : %d, ppid : %d\n",getpid(),getppid());
        printf("\n");
        execvp(file, argv);

        return 0;
}
