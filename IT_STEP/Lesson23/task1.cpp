#include<iostream>
#include<math.h>

using namespace std;
const double pi = 3.14152136;
class Square{
    static int counter;
    public:
        static void counter_add(){
            counter++;
        }
        static int getcounter(){
            return counter;
        }
        double get_sq_triangle(double x, double y,double z){
            double p = (x+y+z)/2;
            counter_add();
            return sqrt((p*(p-x)*(p-y)*(p-z)));
        }
        double get_sq_rect(double x, double y){
            counter_add();
            return x*y;
        }
        double get_sq_romb(double x, double y){
            counter_add();
            return (0.5*x*y);
        }
};
int Square::counter=0;
Square object;
int main(){
    cout<<object.get_sq_triangle(5,5,5)<<endl;
    cout<<object.get_sq_rect(5,5)<<endl;
    cout<<object.get_sq_romb(2,2)<<endl;
    cout<<Square::getcounter()<<endl;
}