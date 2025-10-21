#include<stdio.h>

struct data{

    int age;
    struct time{
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    }timecode;
    struct values{
        float error_code;
        char purpose;
    }value;
    
};
struct data data;
struct data *pointer = &data;

void get_data(){
    printf("%d\n", pointer->age);
    printf("%d/%d/%d\n", pointer->timecode.year, pointer->timecode.month, pointer->timecode.day);
    printf("%d:%d:%d\n", pointer->timecode.hour, pointer->timecode.minute, pointer->timecode.second);
    printf("%.3f %c", pointer->value.error_code, pointer->value.purpose);
}

int main(){
    

    scanf("%d", &pointer->age);
    scanf("%d/%d/%d", &pointer->timecode.year, &pointer->timecode.month, &pointer->timecode.day);
    scanf("%d:%d:%d", &pointer->timecode.hour, &pointer->timecode.minute, &pointer->timecode.second);
    scanf("%.f", &pointer->value.error_code);
    scanf(" %c", &pointer->value.purpose);
    
}