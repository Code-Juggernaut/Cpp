#include<iostream>
using namespace std;

class Circle{
    private:
        static double _scale;
        static int counter;
        double _radius;
        static Circle *instance;

        Circle(int rad):_radius(rad){
            counter++;
        }


    public:

        static Circle *get_instance(){
            if(instance == nullptr){
                instance = new class Circle(10);
            }
            return instance;
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
Circle *Circle::instance;
double Circle::_scale  =1;
int Circle::counter  =0;
int main(){ 
    Circle *pointer = Circle::get_instance();
    pointer->get_scaled();
    cout<<Circle::get_count()<<endl;
    Circle *pointer_2 = Circle::get_instance();
    cout<<Circle::get_count()<<endl;
}