#include <stdio.h>
#include <unistd.h>

int main()
{
   printf("parent pid is %d\n", getpid());

   if (fork() == 0) {
       printf("child pid is %d\n", getpid());
   }

   return 0;
}
