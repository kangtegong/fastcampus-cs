#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define SM_NAME "/myshm"

int main(int argc, char *argv[]) {
  int shmfd;
  int pid;
  int status;
  int *shared_value;

  shmfd = shm_open(SM_NAME, O_RDWR | O_CREAT, 0777);
  if (shmfd == -1) {
    fprintf(stderr, "open error\n");
    exit(1);
  }

  if (ftruncate(shmfd, sizeof(int)) == -1) {
    fprintf(stderr, "truncate error\n");
    exit(1);
  }

  shared_value = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
  close(shmfd);

  *shared_value = 10;

  printf("initial value: %d\n", *shared_value);

  pid = fork();
  if (pid == 0) {

    *shared_value = *shared_value + 1;
    printf("child process increased 1: %d\n", *shared_value);

    sleep(3);

    *shared_value = *shared_value + 5;
    printf("child process increased 5: %d\n", *shared_value);
    munmap(shared_value, sizeof(int));
    exit(1);

  } else if (pid < 0) {
    fprintf(stderr, "fork failure\n");
    exit(1);
  }
  else {
    sleep(1);
    *shared_value = *shared_value + 2;
    printf("parent process increased 2: %d\n", *shared_value);
    wait(&status);
    munmap(shared_value, sizeof(int));
  }
  shm_unlink(SM_NAME);
  return 0;
}
