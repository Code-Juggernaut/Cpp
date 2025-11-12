#include<iostream>
#include<string.h>

using namespace std;

class Number{
    private:
        int _value;
        char *data;
        int len;
    public:
        
        explicit Number(const int value,const char *line):_value(value){
            
            len = strlen(line)+1;
            data = new char[len];
            strcpy(data,line);
        }
        
        Number(){
            _value = 0;
            data = nullptr;
        }
        Number(const class Number& from){
            _value = from._value;
            len = from.len;
            data = new char[len];
            strcpy(data,from.data);
        }
        ~Number(){
            cout<<"deleted!";
            delete[] data;
            
        }
        //================== OVERLOADING ================
        class Number &operator=(const class Number &from){
            
            if(this == &from){
                return *this;
            }
            delete[] data;
            len = from.len;
            data = new char[len];
            strcpy(data,from.data);
            

            _value = from._value;
            return *this;

        }



        class Number operator+(const class Number& val1){
            return Number(_value + val1._value,data);
        }
        class Number operator+(int val){
            return Number(_value+val,data);
        }
        friend class Number operator+(int value, const class Number& class_value);

        class Number operator-(const class Number& val1){
            Number temporary(_value,data);
            temporary._value -=val1._value;
            return temporary;
        }

        class Number operator-(){
            return Number(-_value,data); 
        }

        class Number operator++(){
            ++_value;
            return *this;
        }
        
        class Number operator++(int){
            _value++;
            return *this;
        }
        
        /// @brief printing function
        void print() const{
            cout<<"your value = "<<_value<<endl;
            cout<<"from: "<<data<<endl;
        }
        /// @brief 
        /// @return _value
        const int get_value(){
            return _value;
        }
        
};

class Number operator+(int value, const class Number& class_value){
    return Number(value + class_value._value,class_value.data);
}


int main(){
    Number num(10,"Hello");
    Number num2(100,"World");

    Number result;
    num.print();
    num2.print();

    result = num + num2;
    result.print();
    num.print();

    result = num - num2;
    result.print();

    result = -num;
    result.print();

    result = num + 1;
    result.print();

    result = 1 + num ;
    result.print();

    result++; //prefix
    result.print();

    ++result; //postfix
    result.print();


}