#include<iostream>
#include<string.h>

using namespace std;

class Student{
    private:
    string _Name_surname;
    string _birth_date;
    string _phone;
    string _city;
    string _country;
    string _Univ_name;
    string _living_city;
    string _living_country;
    int _group_num;
    public: 

    void print_all(){
        cout<<"name surname: "<<_Name_surname<<"\n";
        cout<<"birth date: "<<_birth_date<<"\n";
        cout<<"phone: "<<_phone<<"\n";
        cout<<"city: "<<_city<<"\n";
        cout<<"country: "<<_country<<"\n";
        cout<<"university name: "<<_Univ_name<<"\n";
        cout<<"living city: "<<_living_city<<"\n";
        cout<<"living country: "<<_living_country<<"\n";
        cout<<"group num: "<<_group_num<<"\n";
    }

    void edit(){
        cout<<"enter name surname:";
        getline(cin,_Name_surname);
        cout<<"enter birth date:";
        cin>>_birth_date;
        cout<<"enter phone number:";
        cin>>_phone;
        cout<<"enter city:";
        cin>>_city;
        cout<<"enter country:";
        cin>>_country;
        cout<<"enter univ. name:";
        cin>>_Univ_name;
        cout<<"enter living city:";
        cin>>_living_city;
        cout<<"enter living country:";
        cin>>_living_country;
        cout<<"enter group num:";
        cin>>_group_num;
        
    }
    //----------------------------------------SETTERS
    void set_namesurname(string new_data){
        _Name_surname = new_data;
    }
    void set_birth(string new_data){
        _birth_date = new_data;
    }
    void set_city(string new_data){
        _city = new_data;
    }
    void set_country(string new_data){
        _country = new_data;
    }
    void set_univ_name(string new_data){
        _Univ_name = new_data;
    }
    void set_living_city(string new_data){
        _living_city = new_data;
    }
    void set_living_country(string new_data){
        _living_country = new_data;
    }
    void set_phone(string new_data){
        _phone = new_data;
    }
    void set_group(int num){
        _group_num = num;
    }
    //----------------------------------------GETTERS

    string get_namesurname(){
        return _Name_surname;
    }
    string get_birth(){
        return _birth_date;
    }
    string get_city(){
        return _city;
    }
    string get_country(){
        return _country;
    }
    string get_univ_name(){
        return _Univ_name;
    }
    string get_living_city(){
        return _living_city;
    }
    string get_living_country(){
        return _living_country;
    }
    string get_phone(){
        return _phone;
    }
    int get_group(){
        return _group_num;
    }
};
int main(){
    Student pupil;
    pupil.edit();
    pupil.print_all();
}