#include<iostream>
using namespace std;

class point{
    private:
        int _x;
        int _y;
        int _z;
    public:
    //-----------------------------------------------------Constructors
        point(int x,int y,int z):_x(x),_y(y),_z(z){
            _x = x;
            _y = y;
            _z = z;
        };
        point():_x(0),_y(0),_z(0){

        };
        //-------------------------------Functions
        void print(){
            cout<<"x :"<<_x<<" y :"<<_y<<" z :"<<_z<<endl;
        }
        void set(int x, int y, int z){
            _x = x;
            _y = y;
            _z = z;
        }
};

int main(){
    class point Dot;
    class point Dot_two(3,4,5);

    Dot.print();
    Dot_two.print();
}