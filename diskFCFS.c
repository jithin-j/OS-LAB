#include<stdio.h>
#include<stdlib.h>
int n, tracks[25], head, seek_distance;
void fcfsds()
{
    int distance;
    seek_distance = 0;
    int current_track;
    for(int i = 0; i < n; i++)
    {
        current_track = tracks[i];
        distance = abs(tracks[i]-head);
        seek_distance += distance;
        head = current_track;
    }
}
void main(){
    printf("Enter the number of tracks to be seeked: ");
    scanf("%d", &n);
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Enter the seek sequence..");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &tracks[i]);
    }
    fcfsds();
    printf("\n The Seek Sequence is : ");
    for (int i = 0; i < n - 1; i++)
        printf(" %d -> ", tracks[i]);
    printf(" %d\n", tracks[n - 1]);
    printf("\n The Seek Count is : %d\n", seek_distance);
}