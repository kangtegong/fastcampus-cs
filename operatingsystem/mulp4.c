#include <stdio.h>
#include <unistd.h>

void foo() {
   printf("execute foo\n");
}

int main()
{
   if (fork() == 0) {
      if (fork() == 0) {
         printf("child of child pid is %d\n", getpid());
         foo();
      }
      else {
         printf("child pid is %d\n", getpid());
         foo();
      }
   }
   else {
      if(fork() == 0) {
         printf("child pid is %d\n", getpid());
         foo();
      }
      else {
         printf("parent pid is %d\n", getpid());
         foo();
      }
   }

   return 0;
}
