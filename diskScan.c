#include<stdio.h>
#include<stdlib.h>
#define MAX 25
int n, size, seek_count, tracks[25], sequence[25], head;
char dir;
void sort(int arr[], int n)
{
    int temp;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1- i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void Scands()
{
    int current_track, distance,l = 0, r = 0;
    int left[25],right[25];
    int x = 0, run = 2;
    seek_count = 0;
    if(dir == 'L')
    {
        left[l++] = 0;
    }
    else if(dir == 'R')
    {
        right[r++] = size-1;
    }
    for(int i = 0; i < size; i++){
        if(tracks[i]< head)
        {
            left[l++] = tracks[i];
        }
        else
        {
            right[r++] = tracks[i];
        }
    }
    sort(left,l);
    sort(right,r);

    while(run-- > 0)
    {
        if(dir == 'L')
        {
            for(int i = l-1; i >= 0; i--){
                current_track = left[i];
                sequence[x++] = current_track;
                distance = abs(head-current_track);
                head = current_track;
                seek_count += distance;
            }
            dir = 'R';
        }
        else {
            for (int i = 0; i < r; i++) {
                current_track = right[i];
                sequence[x++] = current_track;
                distance = abs(head - current_track);
                seek_count += distance;
                head = current_track;
            }
            dir = 'L';
        }
    }
}
int main(){
int i;
printf("\n SCAN Disk Scheduling\n");
printf("\n Enter the size of the disk : ");
scanf("%d", &size);
printf("\n Enter the number of tracks to be seeked : ");
scanf("%d", &n);
if (n > MAX){
printf("\n Number of tracks to be seeked cannot exceed %d Exiting...\n", MAX);
exit(0);
}
printf("\n Enter the starting position of the head : ");
scanf("%d", &head);
if (head > size) {
printf("\n Starting position of head cannot exceed the size of disk. Exiting...\n");
exit(0);
}
printf("\n Enter the initial direction of the head(L/R) : ");
scanf(" %c", &dir);
if ((dir != 'L') && (dir != 'R')){
printf("\n Invalid direction input. Exiting...\n");
exit(0);
}
printf("\n Enter the tracks to be seeked : ");
for (int i = 0; i < n; i++)
scanf("%d", &tracks[i]);
Scands();
printf("\n The Seek Sequence is : ");
for (i = 0; i < n; i++)
printf(" %d -> ", sequence[i]);
printf(" %d\n", sequence[i]);
printf("\n The Seek Count is : %d\n", seek_count);
return 0;
}