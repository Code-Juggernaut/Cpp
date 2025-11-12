#include<iostream>

using namespace std;

class Vector{
    private:
        int _x;
        int _y;
    public:
        Vector(int x, int y):_x(x),_y(y){

        }
        Vector(){
            _x = 0;
            _y = 0;
        }

        class Vector operator+(class Vector object){
            class Vector New(_x + object._x,_y +object._y);
            return New;
        }
        class Vector operator*(class Vector object){
            class Vector New(_x*object._x, _y*object._y);
            return New;
        }

        friend class Vector operator*(int num, class Vector object){
            class Vector New(object._x * num, object._y * num);
            return New;
        }

        class Vector operator++(int){
            _x++;
            _y++;
            return *this;
        }
        friend class Vector operator-(int val, class Vector object){
            class Vector New(val -object._x ,  val- object._y);
            return New;
        }
        void print(){
            cout<<"X: "<<_x<<" Y: "<<_y<<endl;
        }
};

int main(){
    class Vector vector(10,10);
    class Vector vector2(5,5);
    class Vector result;
    result = vector + vector2;
    result.print();

    result = vector*vector2;
    result.print();

    result = 10*vector;
    result.print();

    result++;
    result.print();

    result = 10 - vector2;
    result.print();
}