#include<iostream>

using namespace std;

double div(double a,double b){
    try{
        if(a == 0 || b== 0){
            throw invalid_argument("DIV ON ZERO!");
            
        }else{
            return a/b;
        }
        
    }
    catch(const invalid_argument &error){
        cout<<"Function exception";
        
    }
    return -1;
}


int f = 10;
int *e = &f;
int **d = &e;
int ***c = &d;
int ****b = &c;
int *****a  = &b;

int main(){
    double a = 10;
    double b = 0;
    double result = 0;
    result = div(a,b);
    try{
        if(a== a+1 || b==b+1){
            throw invalid_argument("DIV ON ZERO!");
        }
        //throw runtime_error("Huston we've got a problems!");
        
        cout<<result;
    }
    catch(const runtime_error &error){
        cout<<"exception detected!"<<error.what();
        
    }
    catch(const invalid_argument &error){
        cout<<" Invalid ARG! "<<error.what();
        
    }
    
}