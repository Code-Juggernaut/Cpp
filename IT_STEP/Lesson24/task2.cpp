#include<iostream>

using namespace std;

class calculator{
    private:
        float _value;
        mutable int counter = 10;
    public:
        calculator():_value(0.0){
        };
        explicit calculator(float val):_value(val){
        }// explicit = запрет на неявную инициал
        
        
        class calculator& add(const float val){
            _value+= val;
            return *this;
        }
        class calculator& sub(const float val){
            _value -= val;
            return *this;
        }
        float get_val() const {
            counter++;
            return _value;
        }
        
};
void print(class calculator *ptr){
    cout<<ptr->get_val()<<endl;
}
int main(){
    class calculator calc;
    calc.add(20);
    print(&calc);
    const class calculator calc_2;
    calc_2.get_val();

    class calculator test(10);
    cout<<test.get_val()<<endl;

    /*class calculator test_2 = 'C';
    cout<<test_2.get_val()<<endl;
*/
    
}