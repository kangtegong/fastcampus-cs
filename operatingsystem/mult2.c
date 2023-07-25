#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *foo() {
   long thread_id = (long int)pthread_self();
   printf("process id is %d\n", getpid());
   printf("this is thread %ld\n", thread_id);
   return NULL;
}

int main() {
   pthread_t thread1;
   pthread_create(&thread1, NULL, foo, NULL);
   pthread_join(thread1, NULL);

   return 0;
}
