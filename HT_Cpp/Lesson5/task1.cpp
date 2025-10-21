#include "header_file.h"
int main(){
    
    long long int array[sizex][sizey];
    cout<<defcolor<<"---array filler---\n";
    cout<<"enter start number:";
    cin>>array[0][0];
    for(int i = 1;i<=sizex;i++){
        array[0][i] = array[0][i-1]*2;
    }
    
    for(int i = 1;i<sizex;i++){
        for(int j = 0;j<sizey;j++){
            if(j == 0){
                array[i][j] = array[i-1][sizey-1]*2;
            }else{
                array[i][j] = array[i][j-1]*2;
            }
        }
    }
    cout<<outcolor<<"array = {\n";
    for(int i = 0;i<sizex;i++){
        cout<<'\t';
        for(int j = 0;j<sizey;j++){

            cout<<array[i][j];
            if(j<sizey-1){
                cout<<" , ";
            }
        }
        if(i<sizex-1){
            cout<<',';
        }

        cout<<'\n';
    }
    cout<<"};";
}