#include<iostream>
#include<string.h>
using namespace std;

class Student{
    private:
        string _name;
        int _grade;
    public:
        Student(string name,int grade):_name(name),_grade(grade){

        }
        friend class Teacher;
};
class Teacher{
    private:
        string _name;
        int _grade;
    public:
        Teacher(string name):_name(name){

        }
        void evaluate(const class Student &object){
            if(object._grade>=90){
                cout<<object._name<<" has excellent mark";
            }else{
                cout<<object._name<<" must work better ";
            }
        }
};

class Calculator{
    private:
        int _secret_multiplyer(int a,int b){
            return a*b;
        }
    public:
        friend class Test;
};
class Test{
    private:

    public:
    void test_secret_multiplyer(){
        Calculator obj1;
        int result = obj1._secret_multiplyer(5,6);
        cout<<endl<<"test "<<result<<endl;
        if(result == 30){
            cout<<"pass"<<endl;
        }else{
            cout<<"fail"<<endl;
        }
    }
};
int main(){
    Student obj1("Object 1",100);
    Teacher god("God");
    god.evaluate(obj1);

    Calculator obj2;
    Test test;
    test.test_secret_multiplyer();
}