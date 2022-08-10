#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    char *segptr;
    char buff[] = "Test";
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
        printf("Creating a new shared memory seg \n");
        printf("SHMID: %d", shmid);
    }
    system("ipcs-m");
    if ((segptr = (char *)shmat(shmid, 0, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    printf("Writing data into shared memory...\n");
    strcpy(segptr, buff);
    printf("Done\n");
    printf("Reading from shared memory...\n");
    printf("Data :- %s \n", segptr);
    printf("Done...\n");
    printf("Deleting shared memory...\n");
    if (shmctl(shmid, IPC_RMID, 0) == -1)
    {
        printf("Cant remove shared memory segment");
    }
    else
    {
        printf("Removed successfully!");
    }
}