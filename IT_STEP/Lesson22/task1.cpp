#include <iostream>
#include<string.h>
using namespace std;
class Notebook{
    string _text;
    public:
    Notebook(string title):_text(title){
    }
    string get(){
        return _text;
    }
    void set(string text){
        _text = text;
    }
};
class Student{
    private:
        char *_name;
        double _grade;
        class Notebook _notebook;
    public:
        Student(): _notebook("Mynotebook"){
            const char *buffer = "name";
            _name = new char[strlen(buffer)+1];
            strcpy(_name,buffer);
            _grade = 0;
        };

        Student (const char *name,double grade):_grade(grade),_notebook("Mynotebook"){
            _name = new char[strlen(name)+1];
            strcpy(_name,name);
            _name[strlen(name)] = '\n';
            _grade = grade;
        };


        ~Student(){
            delete[] _name;
            _name = NULL;
            cout<<"deleted!";
        }
        void print(){
            
            cout<<"Name: "<<_name<<endl;
            cout<<"Grade: "<<_grade<<endl;
            cout<<"My text: "<<_notebook.get()<<endl;
            
        }
        void _print_s(class Student Test){
            Test.print();
        }
        void write_txt(){
            string buff;
            cout<<_name<<" enter text:";
            getline(cin,buff);
            _notebook.set(buff);
        }
};

int main(){
    Student student;
    Student John("John",2.4);
    Student Bob("Bob",4.4);
    Student Alice("Alice",5.0);

    student.write_txt();
    John.write_txt();
    Alice.write_txt();
    Bob.write_txt();

    student.print();
    John.print();
    Bob.print();
    Alice.print();
    student._print_s(John);
}