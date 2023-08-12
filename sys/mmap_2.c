#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHECK_MMAP_SUCCESS(_addr) \
    if (_addr == MAP_FAILED)      \
    {                             \
        perror("mmap");           \
        exit(1);                  \
    }
#define printAddrs(msg)              \
    {                                \
        printf("%s\n", msg);         \
        printf("addr1 = %s", addr1); \
        printf("addr2 = %s", addr2); \
    }

int main(int argc, char *argv[])
{
    int fd;
    caddr_t addr1, addr2;
    char fileName[255] = "input.dat";

    if (argc > 1)
        strcpy(fileName, argv[1]);

    if ((fd = open(fileName, O_RDWR)) == -1)
    {
        perror("open");
        exit(1);
    }
    int pageSize = getpagesize();

    addr1 = mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr1);

    addr2 = mmap(NULL, pageSize, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, (off_t)0);
    CHECK_MMAP_SUCCESS(addr2);

    close(fd);
    printf("%s", addr1);

    addr1[0] = '1';
    printAddrs("After addr1[0]=1");
    addr2[0] = '2';
    printAddrs("After addr2[0]=2"); // CoW
    addr1[0] = '3';
    printAddrs("After addr1[0]=3");

    execlp("cat", "cat", fileName, NULL);

    return 0;
}
