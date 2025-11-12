#ifndef str_functions_H
#define str_functions_H
#include<stdlib.h>
#include<stdint.h>


void* delete_char(uint8_t pos,void *array,uint8_t* size);
void* replace_char(char original,char swap,void *array,uint8_t *size);
void* paste_char(uint8_t pos,char symbol,void *array,uint8_t *size);
void *remove_chars(void *array,uint8_t *size,char letter);
uint8_t find_howmany_nums(void *array,uint8_t *size);
uint8_t find_howmany_letters(void *array,uint8_t *size);
uint8_t find_howmany_symbols(void *array,uint8_t *size);
uint8_t find_howmany_char(char find,void *array,uint8_t *size);

#endif