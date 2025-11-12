#include "header_file.h"
#include<ctime>
#define array_size 4
int attempts = 0;
void random_number(char *array){
    for(int i = 0;i<array_size;i++){
        *(array+i) = (rand()%9) + '0';
    }
}
void is_contain_num(char *user_input,char *code){
    int ok_counter = 0;
    int undef_counter = 0;
    int err_counter = 0;
    char buff[array_size];
    for(int i = 0;i<array_size;i++){
        if(code[i] == user_input[i]){
            //cout<<ok<<"#";
            ok_counter++;
            buff[i] = '#';
        }else{
            bool is_found = 0;
            for(int j = 0;j<array_size;j++){
                if(user_input[j] == code[i]){
                    is_found = 1;
                    //cout<<basic<<"-";
                    buff[j] = '-';
                    undef_counter++;
                    break;
                }
            }
            if(is_found == 0){
                buff[i] = '.';
                //cout<<error<<".";
                err_counter++;
            }
        }
    }
    for(int i = 0;i<array_size;i++){
        switch(buff[i]){
            case '.':cout<<error;break;
            case '#':cout<<ok;break;
            case '-':cout<<basic;break;
        }
        cout<<buff[i];
    }
    cout<<end;
    cout<<ok<<"right_pos and number:"<<ok_counter<<end;
    cout<<basic<<"right_num but incorrect_pos:"<<undef_counter<<end;
    cout<<error<<"incorrect_num and pos:"<<err_counter<<end;
}
bool is_valid(char *user_input,char *code){
    bool flag = 1;
    for(int i = 0;i<array_size;i++){
        if(user_input[i]!=code[i]){
            flag = 0;
            //cout<<basic<<".";
        }else{
            //cout<<ok<<"#";
        }
    }
    return flag;
}
void guess_number(char *input_array,char *array){
    for(int i = 0;i<array_size;i++){
        cin>>input_array[i];
    }
    is_contain_num(input_array,array);
    if(is_valid(input_array,array)==1){
        cout<<ok<<"ACCEPTED";
        cout<<basic<<"Attempts:"<<attempts;
    }else{
        cout<<error<<"try again";
        attempts++;
        guess_number(input_array,array);
    }
}
int main(){
    srand(time(NULL));
    char array[array_size];
    char input_number[array_size];
    random_number(array);
    //------------------------DEBUG--------------------------
    //cout<<array[0]<<array[1]<<array[2]<<array[3];
    //------------------------DEBUG END----------------------
    guess_number(input_number,array);
    //cout<<end<<is_valid(array,input_number);
}