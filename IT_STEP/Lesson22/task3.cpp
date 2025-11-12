#include<iostream>
using namespace std;
class Circle{
    private:
        static double _scale;
        static int counter;
        double _radius;
    public:
        Circle(double radius): _radius(radius){
            counter++;
        }
        double get_scaled(){
            return _radius * _radius *3.1415*_scale;
        }

        static void set_scale(double scale){
            _scale = scale;
        }
        static int get_count(){
            return counter;
        }
        ~Circle(){
            counter--;
            cout<<get_count();
        }
};
double Circle::_scale = 1.0;
int Circle::counter = 0;
int main(){
    Circle::set_scale(2.0);
    Circle round(2.0);
    Circle round_two(4.0);
    cout<<"Area1 = "<<round.get_scaled()<<endl;
    cout<<"Area2 = "<<round_two.get_scaled()<<endl;
    Circle c1(3),c2(4),c3(5),c4(6);
    cout<<Circle::get_count();
}