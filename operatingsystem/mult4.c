#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *foo() {
   printf("foo executed\n");
   return NULL;
}

void *bar() {
   printf("bar executed\n");
   return NULL;
}

void *baz() {
   printf("baz executed\n");
   return NULL;
}

int main() {
   pthread_t thread1;
   pthread_t thread2;
   pthread_t thread3;

   pthread_create(&thread1, NULL, foo, NULL);
   pthread_create(&thread2, NULL, bar, NULL);
   pthread_create(&thread3, NULL, baz, NULL);

   pthread_join(thread1, NULL);
   pthread_join(thread2, NULL);
   pthread_join(thread3, NULL);

   return 0;
}
