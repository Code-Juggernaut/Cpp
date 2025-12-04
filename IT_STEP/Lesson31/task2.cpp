#include<iostream>
#include<string.h>

using namespace std;

class Circle{
    private:
        int rad;
    public:
        Circle(int r):rad(r){
        }
        Circle(){
            rad = 0;
        }
        void set(int r){
            rad = r;
        }
        float getsquare(){
            return (rad*rad)*3.1415;
        }
};

class Cylinder{
    private:
    int size;
    Circle *parts;
    public:
    Cylinder(int rad,int size){
        parts = new struct Circle[size];
        for(int i = 0;i<size;i++){
            parts[i].set(rad);
        }
    }
    float get_volume(){
        float val;
        for(int i = 0;i<size;i++){
            val+=parts[i].getsquare();
        }
        return val;
    }
    float get_square(){
        return parts[0].getsquare(); 
    }
    ~Cylinder(){
        delete[]parts;
    }
};

int main(){
    Cylinder circle(10,6);
    cout<<circle.get_square();
    cout<<circle.get_volume();
}