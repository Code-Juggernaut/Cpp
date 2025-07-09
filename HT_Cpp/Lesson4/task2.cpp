#include"header_file.h"
int main(){
    SetConsoleOutputCP(CP_UTF8);
    const short size = 10;
    int arr1[size];
    int arr2[size];
    int sum[size] = {0};
    cout<<defcolor<<"Введіть числа массивів\n";
    for(int i = 0 ;i<size;i++){
        cout<<"Массив 1 число "<<i+1<<":";
        cin>>arr1[i];
    }
    for(int i = 0;i<size;i++){
        cout<<"Массив 2 число "<<i+1<<":";
        cin>>arr2[i];
    }
    for(int i = 0;i<size;i++){
        sum[i] = arr1[i]+arr2[i];
    }
    cout<<outcolor<<"sum = {";
    for(int i = 0;i<size-1;i++){
        cout<<sum[i]<<", ";
    }
    cout<<sum[size-1];
    cout<<"};\n";
}