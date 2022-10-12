#include<stdio.h>
void main()
{
    int frames[25], pages[25],pageCount,frameCount,least,temp,count[50],time[50],minTime,flag,hit=0;
    printf("Enter number of frames: ");
    scanf("%d", &frameCount);
    printf("Enter the number of pages: ");
    scanf("%d", &pageCount);
    printf("Enter the reference string: \n");
    for(int i = 0; i < pageCount; i++)
    {
        scanf("%d", &pages[i]);
    }
    for(int j = 0; j < frameCount; j++)
    {
        frames[j] = -1;
    }

    for(int i = 0; i < pageCount; i++)
    {   
        flag = 1;
        least = frames[0];
        count[pages[i]]++;
        time[pages[i]] = i;
        for(int j = 0; j < frameCount; j++)
        {
            if(frames[j] == -1 || frames[j] == pages[i])
            {
                if(frames[j]!=-1)
                {
                    hit++;
                }
                flag = 0;
                frames[j] = pages[i];
                break;
            }
            if(count[least]>count[frames[j]])
            {
                least = frames[j];
            }
        }
        if(flag)
        {
            minTime = 50;
            for(int j = 0; j < frameCount; j++)
            {
                if(count[frames[j]] == count[least] && time[frames[j]]<minTime)
                {
                    temp = j;
                    minTime = time[frames[j]];
                }
            }
            count[frames[temp]] = 0;
            frames[temp] = pages[i];
        }
        for(int j = 0; j < frameCount; j++)
        {
            printf("%d", frames[j]);
        }
        printf("\n");
    }
    printf("Page hit: %d\n", hit);
}