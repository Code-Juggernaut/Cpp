#include<iostream>
#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#define default_color 0xFFFF

using std::cout;
using std::cin;

uint16_t rgb_to_565(uint8_t r, uint8_t g, uint8_t b) {
    uint16_t red   = (r >> 3) & 0x1F;  // 5 bits
    uint16_t green = (g >> 2) & 0x3F;  // 6 bits
    uint16_t blue  = (b >> 3) & 0x1F;  // 5 bits
    return (red << 11) | (green << 5) | blue;
}

void rgb565_to_rgb888(uint16_t color565,int isvisible = 1) {
    uint8_t r = ((color565 >> 11) & 0x1F) * 255 / 31;
    uint8_t g = ((color565 >> 5) & 0x3F) * 255 / 63;
    uint8_t b = (color565 & 0x1F) * 255 / 31;
    //cout <<"\033[38;2;"<<r<<";"<<g<<";"<<b<<"m⁠▓\033[0m";
    if(isvisible == 1){
        printf("\033[38;2;%d;%d;%dm%c",r,g,b,0xB2);
    }else{
        printf("\033[38;2;%d;%d;%dm",r,g,b);
    }
    // cout<<"\033[38;2;255;100;255m Hello, Car World!\033[0m\n";
}
struct Car{
    private:

    uint16_t color; // 565 color
    char *model;
    int sizeof_model;
    char type;
    union{
        int number;
        char string[8];
    };

    public:
    void edit(){
        uint8_t *pointer = (uint8_t*)malloc(3);
        cout<<"enter color(RGB 888format):\n";
        for(int i = 0;i<3;i++){
            switch(i){
                case 0:cout<<"r:";break;
                case 1:cout<<"g:";break;
                case 2:cout<<"b:";break;
            }
            scanf("%d",&pointer[i]);
        }
        color = rgb_to_565(pointer[0],pointer[1],pointer[2]);
        free(pointer);

        sizeof_model = 0;
        cout<<"Using '.' to end line";
        model = (char*)malloc(sizeof_model+1);
        while(model[sizeof_model]!='.'){
            cin>>model[sizeof_model];
            if(model[sizeof_model]!='.'){
                sizeof_model++;
                model = (char*)realloc(model,sizeof_model+1);
            }
        }
        model[sizeof_model] = '\0';
        char command;
        cout<<"enter command(N or S)";
        cin>>command;
        switch(command){
            case 'N':cin>>number;type = 'N';break;
            case 'S':cout<<"CAUTION! MAX 8 chars\n";type = 'S';cin>>string;break;
        }
    }
    void print(){
        cout<<"model:"<<model<<'\n';
        cout<<"color:";
        rgb565_to_rgb888(color);
        rgb565_to_rgb888(default_color,0);
        cout<<"\n number";
        if(type == 'S'){
            cout<<string;
        }else{
            cout<<(int)number;
        }

    }
    void delete_data(){
        free(model);
        sizeof_model = 0;
        if(type =='S'){
            for(int i = 0;i<8;i++){
                string[i] = ' ';
            }
        }else{
            number = 0;
        }
        type = !0;
        color = default_color;
    }
};


void print_all(struct Car *pointer,int size){
    for(int i = 0;i<size;i++){
        cout<<"\n---------------------------\n";
        pointer[i].print();
        cout<<"\n---------------------------\n";
    }
}

void edit(struct Car *pointer,int size = 0){
    if(size == 0){
        int pos = 0;
        cout<<"enter edit pos:";
        cin>>pos;
        pointer[pos].edit();
    }else{
        for(int i = 0;i<size;i++){
            cout<<"editing car"<<i<<":\n";
            pointer[i].edit();
        }   

    }
}
void find_car(struct Car *pointer,int searchpos){
    pointer[searchpos].print();
}
void delete_car(struct Car *pointer,int size){
    cout<<"\033[91m WIPING DATA...";
    for(int i = 0;i<size;i++){
        pointer[i].delete_data();
    }
    free(pointer);
    cout<<"\033[92m WIPING SUCCESSFUL!!!";
}
int main(){

    int size = 0;
    cout<<"enter howmany cars";
    cin>>size;
    struct Car *pointer = (struct Car*)malloc(sizeof(struct Car)*(size)+1);
    
    edit(pointer,size);
    print_all(pointer,size);
    {
        int pos = 0;
        cout<<"enter where to find:";
        cin>>pos;
        find_car(pointer,pos);
    }
    
    {
        int pos = 0;
        
        edit(pointer);
    }
    print_all(pointer,size);

    delete_car(pointer,size);
}