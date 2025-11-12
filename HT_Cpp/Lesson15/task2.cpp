#include<iostream>
#include<stdlib.h>
#include<stdint.h>
#include<cstring>

#define Def_color 0xffff

using std::cin;
using std::cout;
using std::string;

enum _class{HUMAN,BIRD,ANIMAL,NN,UNDEFINED};

enum _hazard{NONE,MINIMAL,AVERAGE,HIGH,EXTREME,DEATHFUL};

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


struct Bionic{
    private:
    float speed;
    _class type;
    uint16_t color;

    union{
        float flight_speed;
        int IQ;
        int is_on_two_legs;
        float power_consumption;
        _hazard hazard;
    };
    public:
    void edit(){
        
        cout<<"enter speed";
        cin>>speed;

        cout<<"enter color:";
        char rgb[3];

        for(int i = 0;i<3;i++){
            switch(i){
                case 0:cout<<"r:";break;
                case 1:cout<<"g:";break;
                case 2:cout<<"b:";break;
            }
            scanf("%d",&rgb[i]);
        }
        color = rgb_to_565((uint8_t)rgb[0],(uint8_t)rgb[1],(uint8_t)rgb[2]);
        
        cout<<"enter class";
        char *buffer = (char*)malloc(1);
        buffer[0] =' ';
        int size = 0;
        while(buffer[size] !='.'){
            scanf(" %c",&buffer[size]);
            if(buffer[size]!='.'){
                size++;
                buffer = (char*)realloc(buffer,size+1);
            }
        }
        buffer[size] = '\0';
        
        if(!strcmp(buffer,"BIRD")){
            type = BIRD;
            cout<<"enter flightspeed";
            cin>>flight_speed;
        }else if(!strcmp(buffer,"HUMAN")){
            type = HUMAN;
            cout<<"enter IQ";
            cin>>IQ;
        }else if(!strcmp(buffer,"ANIMAL")){
            type = ANIMAL;
            cout<<"enter is on two legs";
            cin>>is_on_two_legs;
            is_on_two_legs = (is_on_two_legs != 0)?1:0;
        }else if(!strcmp(buffer,"NN")){
            cout<<"enter power_consumption";
            type = NN;
            cin>>power_consumption;
        }else{
            type = UNDEFINED;
            char _hazard;
            cout<<"enter biohazard(N/M/A/H/E/D):";
            cin>>_hazard;
            switch(_hazard){
                case 'N':hazard = NONE;break;
                case 'M':hazard = MINIMAL;break;
                case 'A':hazard = AVERAGE;break;
                case 'H':hazard = HIGH;break;
                case 'E':hazard = EXTREME;break;
                case 'D':hazard = DEATHFUL;break;
            }
        }
        free(buffer);
    }

    void print(){
        cout<<speed<<'\n';
        cout<<"color:";
        rgb565_to_rgb888(color);
        rgb565_to_rgb888(Def_color,0);
        cout<<'\n';
        
        switch(type){
            case BIRD:cout<<"BIRD\n";cout<<"Flightspeed = "<<flight_speed<<'\n';break;
            case ANIMAL:cout<<"ANIMAL\n";cout<<"Is on two legs"<<((is_on_two_legs == 0)?"No":"Yes")<<'\n';break;
            case HUMAN:cout<<"HUMAN\n";cout<<"IQ"<<IQ<<'\n';break;
            case NN:cout<<"NN\n";cout<<"Power consumption"<<power_consumption<<'\n';break;
            case UNDEFINED:cout<<"UNDEFINED\n";cout<<"Biohazard:";
                switch(hazard){
                    case NONE:cout<<"\033[96mNONE";break;
                    case MINIMAL:cout<<"\033[92mMINIMAL";break;
                    case AVERAGE:cout<<"\033[93mAVERAGE";break;
                    case HIGH:cout<<"\033[99mHIGH";break;
                    case EXTREME:cout<<"\033[95mEXTREME";break;
                    case DEATHFUL:cout<<"\033[90mDEATHFUL";break;
                }
                cout<<'\n';break;
        }
    }
    int get(char type){
        switch(type){
            case 'T':return type;break;
            case 'F':return flight_speed;break;
            case 'I':return IQ;break;
            case 'L':return is_on_two_legs;break;
            case 'P':return power_consumption;break;
            case 'H':return hazard;break;
        }
        return 0;
    }
};

void print_all(struct Bionic *pointer,int size){
    for(int i = 0;i<size;i++){
        cout<<"\n--------------------\n";
        pointer[i].print();
        cout<<"\n--------------------\n";
    }
}
void edit_data(struct Bionic *pointer,int size = 0){
    if(size == 0){
        int pos = 0;
        cout<<"enter edit pos:";
        cin>>pos;
        pointer[pos].edit();
    }else{
        for(int i = 0;i<size;i++){
            cout<<"editing Entity "<<i<<":\n";
            pointer[i].edit();
        }   

    }
}
void find(struct Bionic *pointer,int size){
    char *characteristic = (char*)malloc(1);
    int pos = 0;
    cout<<"IQ/FLIGHTSPEED/IS_2_LEGS/POWER_CONS/HAZARD\n";
    cout<<"enter search query(use '.' to end):";
    while(characteristic[pos] !='.'){
        scanf(" %c",&characteristic[pos]);
        if(characteristic[pos]!= '.'){
            pos++;
            characteristic = (char*)realloc(characteristic,pos+1);
        }
    }
    characteristic[pos] = '\0';

    if(!strcmp(characteristic,"FLIGHTSPEED")){
        float search;
        cout<<"Enter search value:";
        cin>>search;
        for(int i = 0;i<size;i++){
            if(pointer[i].get('T') == BIRD){
                if(pointer[i].get('F') == search){
                    cout<<"found at"<<i<<'\n';
                    pointer[i].print();
                }
            }
        }
    }else if(!strcmp(characteristic,"IQ")){
        int search;
        cout<<"Enter search value:";
        cin>>search;
        for(int i = 0;i<size;i++){
            if(pointer[i].get('T') == HUMAN){
                if(pointer[i].get('I') == search){
                    cout<<"found at"<<i<<'\n';
                    pointer[i].print();
                }
            }
        }
    }else if(!strcmp(characteristic,"IS_2_LEGS")){
        int search;
        cout<<"Enter search value:";
        cin>>search;
        search = (search>=1)?1:0;
        for(int i = 0;i<size;i++){
            if(pointer[i].get('T') == ANIMAL){
                if(pointer[i].get('L') == search){
                    cout<<"found at"<<i<<'\n';
                    pointer[i].print();
                }
            }
        }
    }else if(!strcmp(characteristic,"POWER_CONS")){
        float search;
        cout<<"Enter search value:";
        cin>>search;
        for(int i = 0;i<size;i++){
            if(pointer[i].get('T') == NN){
                if(pointer[i].get('P') == search){
                    cout<<"found at"<<i<<'\n';
                    pointer[i].print();
                }
            }
        }
    }else{
        int search;
        cout<<"Enter search value(from 0 to 5):";
        cin>>search;
        for(int i = 0;i<size;i++){
            if(pointer[i].get('T') == UNDEFINED){
                if(pointer[i].get('H') == search){
                    cout<<"found at"<<i<<'\n';
                    pointer[i].print();
                }
            }
        }
    }
    free(characteristic);
}
int main(){
    int size = 0;
    cout<<"enter size: ";
    cin>>size;
    struct Bionic *entity;
    entity = (struct Bionic*)malloc(sizeof(struct Bionic)*size);
    edit_data(entity,size);
    print_all(entity,size);
    find(entity,size);

}