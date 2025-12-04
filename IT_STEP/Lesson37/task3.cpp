#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

class Student{
    private:
        string _name;
        int _grade;
    public:
        Student(const string &name,const int &grade):_name(name),_grade(grade){

        }
        int get_grade()const{
            return _grade;
        }
        friend ostream& operator<<(ostream &stream, const Student &data){
            stream<<data._name<<" ("<<data._grade<<")"<<endl;
            return stream;
        }
};

int main(){
    vector<Student> students = {{"Mark",10},{"John",3},{"Bob",9},{"Eva",6}};
    cout<<" <INFO> ";
    for(const Student &i:students){
        cout<<i;
    }
}