#include "header_file.h" 

int main() {
    SetConsoleOutputCP(CP_UTF8); // Вивід у UTF-8
    int buff[10] = {0,0,0,0,0,0,0,0,0,0};
    int arr1[5] = {0,0,0,0,0};
    int arr2[5] = {0,0,0,0,0};
    cout<<defcolor<<"----Ретранслятор----\n";
    cout<<"Введіть числа\n";
    for(int i = 0;i<10;i++){
        cout<<"Число"<<i+1<<":";
        cin>>buff[i];

    }
    for(int i = 0;i<10;i++){
        if(i<5){
            arr1[i] = buff[i];
        }else{
            arr2[i-5] = buff[i]; 
        }
    }
    cout<<message<<"Массив 1:";
    for(int i = 0;i<5;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<ok<<"\nМассив 2:";
    for(int i = 0;i<5;i++){
        cout<<arr2[i]<<" ";
    }
}
