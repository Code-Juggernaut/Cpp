#include "header_file.h"
template <typename templ>
bool find_num_in_array(templ* array,int size,templ num){//фокус з * показав chatgpt
    for(int i = 0;i<size;i++){
        if(array[i] == num){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[] = {24,45,2,3,3,4,6,2,3};
    int num = 0;
    cout<<basic<<"enter find number:"<<input;
    cin>>num;
    if(find_num_in_array(arr,sizeof(arr)/sizeof(arr[0]),25)){
        cout<<ok<<"FOUND";
    }else{
        cout<<error<<"Not found";
    }
}