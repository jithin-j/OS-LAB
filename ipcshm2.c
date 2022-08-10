#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#define SEGSIZE 100

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char buff[] = "Test";
    char *segptr;
    key = ftok(".", "s");
    if ((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if ((shmid = shmget(key, SEGSIZE, 0)) == -1)
        {
            perror("shmget");
            exit(1);
        }
    }
    else
    {
        printf("Creating shared memory...\n");
        printf("SHMID: %d", shmid);
    }
    system("ipcs-m");
    if ((segptr = (char *)shmat(shmid, 0, 0) == (char *)-1))
    {
        perror("shmat");
        exit(1);
    }
}