#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
struct dirent *dptr;
int main(int argc, char *argv[])
{
    char buff[100];
    DIR *dirp;
    printf("Enter directory name: \n");
    scanf("%s", buff);
    if ((dirp = opendir(buff)) == NULL)
    {
        printf("Given directory doesnt exist...\n");
        exit(1);
    }
    while (dptr = readdir(dirp))
    {
        printf("%s", dptr->d_name);
    }
    closedir(dirp);
}