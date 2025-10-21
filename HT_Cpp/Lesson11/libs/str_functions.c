#include"str_functions.h"

void* delete_char(uint8_t pos,void *array,uint8_t* size){
    void *buffer =malloc(*(size)-1);
    uint8_t flag = 0;
    for(uint8_t i = 0;i<(*size);i++){
        if(i != pos){
            ((uint8_t*)buffer)[flag == 0?i:i-1] = ((uint8_t*)array)[i];
        }else{
            flag = 1;
        }
    }
    free(array);
    (*size)--;
    return buffer;
}

void* replace_char(char original,char swap,void *array,uint8_t *size){
    for(uint8_t i = 0;i<(*size);i++){
        ((char*)array)[i] = (((char*)array)[i] == original)?swap:((char*)array)[i];
    }

    return array;
}

void* paste_char(uint8_t pos,char symbol,void *array,uint8_t *size){
    if(*(size)>=255){
        return NULL;
    }
    uint8_t flag = 0;
    void *buffer = malloc((*size)+1);
    for(uint8_t i = 0;i<(*size)+1;i++){
        if(i == pos){
            ((char*)buffer)[i] = symbol;
            flag = 1;
        }
        if(flag == 0){
            ((char*)buffer)[i] = ((char*)array)[i];
        }else{
            ((char*)buffer)[i+1] = ((char*)array)[i];
        }
    }
    free(array);
    (*size)++;
    return buffer;
}

void *remove_chars(void *array,uint8_t *size,char letter){
    uint8_t new_size = *(size);
    for(uint8_t i =0 ;i<*(size);i++){
        if(((char*)array)[i] == letter){
            new_size--;
        }
    }
    uint8_t pos = 0;
    void *buffer = malloc(*size);
    for(uint8_t i = 0;i<(*size);i++){
        if(((char*)array)[i] != letter){
            ((char*)buffer)[pos] =((char*)array)[i];
            pos++;
        }
    }
    free(array);
    *(size) = new_size;
    return buffer;
}

uint8_t find_howmany_nums(void *array,uint8_t *size){
    uint8_t howmany_nums = 0;
    for(uint8_t i = 0;i<(*size);i++){
        if(((char*)array)[i] < 0x3A && ((char*)array)[i]>=0x30){
            howmany_nums++;
        }
    }
    return howmany_nums;
}
uint8_t find_howmany_letters(void *array,uint8_t *size){
    uint8_t howmany_letters = 0;
    for(uint8_t i = 0;i<(*size);i++){
        if(((char*)array)[i] <= 0x5A && ((char*)array)[i]>=0x41){
            howmany_letters++;
        }else if(((char*)array)[i] <= 0x7A && ((char*)array)[i]>=0x61){
            howmany_letters++;
        }
    }
    return howmany_letters;
}
uint8_t find_howmany_symbols(void *array,uint8_t *size){
    uint8_t howmany_symbols = 0;
    for(uint8_t i = 0;i<(*size);i++){
        if(((char*)array)[i] < 0x30){
            howmany_symbols++;
        }else if(((char*)array)[i]>=0x3A && ((char*)array)[i]<0x41){
            howmany_symbols++;
        }else if(((char*)array)[i]>=0x5B && ((char*)array)[i]<0x61){
            howmany_symbols++;
        }else if(((char*)array)[i]>=0x7B){
            howmany_symbols++;
        }
    }
    return howmany_symbols;
}
uint8_t find_howmany_char(char find,void *array,uint8_t *size){
    uint8_t howmany_chars = 0;
    for(uint8_t i = 0;i<(*size);i++){
        if(((char*)array)[i] == find){
            howmany_chars++;
        }
    }
    
    free(array);
    array = NULL;
    (*size) = 0;
    return howmany_chars;
}