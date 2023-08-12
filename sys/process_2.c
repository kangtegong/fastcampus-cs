#include <unistd.h>
#include <stdio.h>

int main(){
        char *arg1 = "-al";
        char *arg2 = "/etc";
        char *file = "ls";
        char *argv[] = {file, arg1, arg2, NULL};
        char *path = "/bin/ls";

        // printf("execl 호출: \n");
        // execl(path, file, arg1, arg2, NULL);

        // printf("execlp 호출: \n");
        // execlp(file, file, arg1, arg2, NULL);

        // printf("execle 호출: \n");
        // execle(path, file, arg1, arg2, NULL, NULL);

        // printf("execv 호출: \n");
        // execv(path, argv);

        // printf("execvp 호출: \n");
        // execvp(file, argv);

        // printf("execvpe 호출: \n");
        // execvpe(file,argv,NULL);

        // printf("execve호출: \n");
        // execve(path, argv, NULL);

        return 0;
}
