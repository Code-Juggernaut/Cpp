#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(){
    FILE *file;
    file = fopen("program.bin","wb");
    uint8_t *array = (uint8_t*)malloc(5*sizeof(uint8_t));
    for(uint8_t i = 0;i<5;i++){
        array[i] = rand()%10+100;
    }
    fwrite(array,sizeof(uint8_t),5,file);
    fclose(file);
    free(array);
    array = (uint8_t*)malloc(5*sizeof(uint8_t));
    
    fopen("program.bin","rb");
    fread(array,sizeof(uint8_t),5,file);

    for(uint8_t i = 0;i<5;i++){
        printf("%d ",(char)array[i]);
    }
    fclose(file);
    free(array);
}