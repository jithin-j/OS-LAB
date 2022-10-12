#include<stdio.h>
int findLRU(int time[], int fCount);
void LRU(int pages[], int frames[], int pCount, int fCount, int time[]);
void main()
{
    int pages[25],frames[25],pC, fC, time[25];
    printf("Enter the number of frames: ");
    scanf("%d", &fC);
    for(int i = 0; i < fC; i++){
        frames[i] = -1;
    }
    printf("Enter the number of pages: ");
    scanf("%d", &pC);
    printf("Enter the reference string");
    for(int i = 0; i < pC; i++){
        scanf("%d", &pages[i]);
    }
    LRU(pages, frames, pC, fC, time);
}
int findLRU(int time[], int fCount){
    int k,min,pos;
    min = time[0];
    pos = 0;
    for(k = 1; k < fCount; k++){
        if(time[k]<min){
            min = time[k];
            pos = k;
        }
    }
    return pos;
}

void LRU(int pages[], int frames[], int pCount, int fCount, int time[])
{
    int faultcount = 0, queue = 0, count = 0;
    for(int i = 0; i < pCount; i++)
    {
        int flag = 0;
        printf("%d\t|\t", pages[i]);
        for(int j = 0; j < fCount; j++){
            if(pages[i] == frames[j])
            {
                flag = 1;
                count++;
                time[j] = count;
                printf("Hit\n");
                break;
            }
        }
        if(flag == 0 && queue<fCount){
            count++;
            faultcount++;
            frames[queue] = pages[i];
            time[queue] = count;
            queue++;
        }
        else if(flag == 0 && queue==fCount)
        {
            count++;
            faultcount++;
            int loc = findLRU(time, fCount);
            frames[loc] = pages[i];
            time[loc] = count;
        }
        if(flag == 0){
            for(int j = 0; j < fCount; j++){
                printf("%d ", frames[j]);
            }
            printf("\n\n");
        }
    }
    printf("Total number of Page Faults: %d", faultcount);
}