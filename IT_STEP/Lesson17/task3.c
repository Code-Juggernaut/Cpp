#include<stdio.h>
#include<stdlib.h>

int main(){
    char filename[12];
    scanf("%s",filename);
    FILE *file;
    file = fopen(filename,"wb");
    int *randomnums = (int*)malloc(sizeof(int)*10);
    for(int i = 0;i<10;i++){
        randomnums[i] %=10;
    }
    fwrite(randomnums,sizeof(int),10,file);
    for(int i = 0;i<10;i++){
        printf("%d ",randomnums[i]);
    }
    fclose(file);
    free(randomnums);
    

    file = fopen(filename,"rb");
    randomnums = (int*)malloc(sizeof(int)*10);    

    fread(randomnums,sizeof(int),10,file);
    printf("\n");

    int max =randomnums[0];
    for(int i = 0;i<10;i++){
        printf("%d ",randomnums[i]);
        max = (max<randomnums[i])?randomnums[i]:max;
    }
    printf("\nmax = %d",max);
    free(randomnums);
    fclose(file);
}