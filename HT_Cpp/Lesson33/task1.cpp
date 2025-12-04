#include<iostream>
#include<stack>
#include<math.h>

using namespace std;
class Algebra{
    public:
        virtual double output() = 0;
};

class Linear:public Algebra{
    private:
        stack<float>nums;
        char _operand;
    public:
        Linear(const float x, const char operand, const float y):
        _operand(operand){
            nums.push(x);
            nums.push(y);
            
        }

        double output(){
            double result  = nums.top();
            nums.pop();
            while(!nums.empty()){
                switch(_operand){
                    case '-':result -= nums.top();break;
                    case '+':result += nums.top();break;
                    case '*':result *= nums.top();break;
                    case '/':result /= (nums.top()==0?(1):nums.top());break;
                }
                nums.pop();
            }
            return result;
        }
};
class Squared:public Algebra{
    private:
        double _x,_y,_z;
        double Discriminant()const{
            return _y*_y - 4*_x*_z;
        }
    public:
        Squared(const float x, const float y,const float z):
        _x(x),_y(y),_z(z){
        }

        double output(){
            double result;
            if(Discriminant()<0){
                return 0.00;
            }
            cout<<"x = "<<((-_y+sqrt(Discriminant()))/(_x*2))<<endl;
            cout<<"x = "<<((-_y-sqrt(Discriminant()))/(_x*2))<<endl;
            result = ((-_x+sqrt(Discriminant()))/(_x*2));
            return result;
        }
};
int main(){
    Linear data(4,'*',2); // ax (+-*/)b = 0;
    cout<<"x = "<<data.output()<<endl;
    Squared data1(1,-5,6);
    data1.output();
}