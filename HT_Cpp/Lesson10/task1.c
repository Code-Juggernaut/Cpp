#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define DEBUG 1

float min(int16_t* buffer,uint8_t size){
    int16_t min = buffer[0]; 
    for(uint8_t i = 0;i<size;i++){
        min = min>buffer[i]?buffer[i]:min;
    }
    return min;
}
float max(int16_t* buffer,uint8_t size){
    int16_t max = buffer[0]; 
    for(uint8_t i = 0;i<size;i++){
        
        max = max<buffer[i]?buffer[i]:max;
    }
    return max;
}
float avr(int16_t* buffer,uint8_t size){
    float avr =0; 
    for(uint8_t i = 0;i<size;i++){
        avr+=buffer[i];
    }
    return avr/size;
}

void menu(){
    //-----------------------------------GET OPERATION--------------------------
    char *buff = (char*)malloc(3);
    
    float(*function_ptr[3])(int16_t*,uint8_t) = {min,max,avr};
    uint8_t operation = 0;
    printf("Choose function:(min,max or avr)\n");
    for(uint8_t i = 0;i<3;i++){
        
        scanf("%c",&buff[i]);
        
    }
    if(buff[0] == 'm'&&buff[1] == 'i'&&buff[2] == 'n'){
        #ifdef DEBUG
        printf("min");
        #endif
        operation = 0;
    }else if(buff[0] == 'm'&&buff[1] == 'a'&&buff[2] == 'x'){
        #ifdef DEBUG
        printf("max");
        #endif
        operation = 1;
    }else{
        #ifdef DEBUG
        printf("avr");
        #endif
        operation = 2;
    }
    printf("\n");
    free(buff);
    printf("Enter numbers(|-terminator)\n");
    //-------------------------------------------GET NUMBERS-------------
    char terminator = ' ';
    int size = 0;
    int16_t* buffer = (int16_t*)malloc(sizeof(int16_t));
    
    while (terminator!='|'){
        scanf("%d%c",&buffer[size],&terminator);
        if(buffer[size] !='|'){
            size++;
            buffer = (int16_t*)realloc(buffer,(size+1)*sizeof(int16_t));
        }
    }
    #ifdef DEBUG
    for(int i = 0;i<size;i++){
        printf("%d ",buffer[i]);
    }
    #endif
    printf("\n%.3f",function_ptr[operation](buffer,size));
    free(buffer);

}

int main(){
    menu();
}