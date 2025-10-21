#include<iostream>

using namespace std;

class calculator{
    private:
        float _value;
    public:
        calculator():_value(0.0){
        };

        class calculator& add(float val){
            _value+= val;
            return *this;
        }
        class calculator& sub(float val){
            _value -= val;
            return *this;
        }
        class calculator& multiply(float val){
            _value*=val;
            return *this;        
        }
        class calculator& div(float val){
            val = (val == 0.0?1:val);
            _value/=val;
            return *this;
        }
        class calculator& pow(int val){
            for(int i = 1;i<val;i++){
                _value*=_value;
            }
            return *this;
        }
        class calculator& set_value(float val){
            _value = val;
            return *this;
        }
        float get_val(){
            return _value;
        }
};

int main(){
    calculator calc;
    calc.add(5);
    calc.multiply(10);
    calc.sub(7);
    cout<<calc.get_val();
    calc.add(100).sub(10).multiply(0.4);
    cout<<" "<<calc.get_val();
    calc.set_value(5);
    calc.pow(2);
    cout<<" "<<calc.get_val();
}