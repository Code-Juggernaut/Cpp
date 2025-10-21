#include "header_file.h"
int main(){
    cout<<defcolor<<"----  numbers(TASK1 and TASK2) ----\n";
    int counter = 0;
    int diff_counter = 0;
    int number[3] = {0,0,0};

    for(int i = 1;i<10;i++){
        for(int j = 0;j<10;j++){
            for(int z = 0;z<10;z++){
                number[0] = i;
                number[1] = j;
                number[2] = z;
                if(number[0] == number[1]&& number[0]!= number[2]){

                    counter++;
                }else if(number[1] == number[2]&& number[1]!= number[0]){

                    counter++;
                }else if(number[2] == number[0]&& number[2]!=number[1]){

                    counter++;
                }
                if(number[0]!=number[1]&&number[1]!=number[2]&&number[0]!=number[2]){
                    diff_counter++;
                }
            }
        }
    }
    cout<<'\n'<<"counted elements = "<<message<<counter<<'\n'<<defcolor<<"counted different elements = "<<message<<diff_counter;
}