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
   pthread_t thread2;
   pthread_t thread3;

   pthread_create(&thread1, NULL, foo, NULL);
   pthread_create(&thread2, NULL, foo, NULL);
   pthread_create(&thread3, NULL, foo, NULL);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);
   pthread_join(thread3, NULL);

   return 0;
}
