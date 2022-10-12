#include<stdio.h>
void main(){
    int nb, nf, fs[25], bs[25], temp, frag[25];
    static int ff[25], bf[25];
    printf("Enter the number of files: ");
    scanf("%d", &nb);
    printf("Enter the number of blocks: ");
    scanf("%d", &nf);
    printf("Enter the file sizes: \n");
    for(int i = 1; i <= nf; i++){
        printf("File[%d]: ", i);
        scanf("%d", &fs[i]);
    }
    printf("Enter the block sizes: \n");
    for(int i = 1; i <= nb; i++){
        printf("Block[%d]: ", i);
        scanf("%d", &bs[i]);
    }
    for(int i = 1; i <= nf; i++){
        for(int j = 1; j<=nb; j++){
            if(bf[j]!=1){
                temp = bs[j]-fs[i];
                if(temp >= 0)
                {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }
    printf("\nFileNo:\tFile_Size:\tBlock_No:\tBlock_size:\tFragment:");
    for(int i = 1; i <= nf; i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i,fs[i],ff[i],bs[ff[i]], frag[i]);
    }
}