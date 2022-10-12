#include<stdio.h>
void main()
{
    int n, m,p[30],rs[30],flag=1,k=0,i1=0,i=0;
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    while(1){
        scanf("%d", &rs[i]);
        if(rs[i] == 0)
            break;
        i++;
    }
    m = i;
    for(int j=0; j < n; j++)
    {
        p[j]=0;
    }
    for(int i = 0; i < m; i++)
    {
        flag = 1;
        for(int j = 0; j < n; j++){
            if(p[j]==rs[i]){
                printf("Data already exists in page..\n");
                flag=0;
                break;
            }
        }
        if(flag==1){
            p[i1]=rs[i];
            i1++;
            k++;
            if(i1==n)
                i1=0;
        }
        for(int j = 0; j < n ;j++)
        {
            printf("\npage %d: %d", j+1, p[j]);
            if(p[j] == rs[i])
            {
                printf("*");
            }
        }
        printf("\n\n");
    }
    printf("The number of page faults: %d", k);
}