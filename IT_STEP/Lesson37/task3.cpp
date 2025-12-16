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
        bool operator<(const Student &other){
            return this->_grade<other._grade;
        }
        friend ostream& operator<<(ostream &stream, const Student &data){
            stream<<data._name<<" ("<<data._grade<<")"<<endl;
            return stream;
        }
};

int main(){
    vector<Student> students = {{"Mark",10},{"John",3},{"Bob",9},{"Eva",6}};
    cout<<" <INFO> "<<endl;
    for(const Student &i:students){
        cout<<i;
    }
    sort(students.begin(),students.end());
    cout<<endl;
    cout<<" <INFO> "<<endl;
    for(const Student &i:students){
        cout<<i;
    }
    sort(students.begin(),students.end(),[](const Student &this_,const Student &other){return this_.get_grade()>other.get_grade();});
    cout<<" <INFO> "<<endl;
    for(const Student &i:students){
        cout<<i;
    }
    students.erase(remove_if(students.begin(),students.end(),[](const Student &this_){return this_.get_grade()<6;}),students.end());
    
    cout<<" <INFO> "<<endl;
    for(const Student &i:students){
        cout<<i;
    }
}