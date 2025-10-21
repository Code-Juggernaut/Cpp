#include<iostream>
#include<string.h>

using namespace std;
class Box{
    private:
    double _width;
    double _length;
    double _height;
    char *_name;
    public:
    /*Box(){
        _width = 0.0;
        _length = 0.0;
        _height = 0.0;
        _name = new char [strlen("NULL")+1];
    }*/
    Box(double width,double length,double height,const char *name){
        _width = width;
        _length = length;
        _height = height;
        _name = new char [strlen(name)+1];
        for(int i = 0;i<strlen(name)+1;i++){
            _name[i] = name[i];
        }

    }
    void set_width(double width){
        _width = width;
    }
    double get_width(){
        return _width;
    }

    void input(double width,double length,double height){
        _width = width;
        _length = length;
        _height = height;
    }
    void get_info(){
        cout<<"width: "<<_width<<'\n';
        cout<<"Length: "<<_length<<'\n';
        cout<<"Height: "<<_height<<'\n';
        cout<<"address: "<<_name<<'\n';
    }
    double getVolume(){
        return _width*_length*_height;
    }

    ~Box(){
        cout<<"destructed";
        delete[] _name;
    }
};

int main(){
    class Box korobka{0,0,0,"NULL"};
    class Box korobka_pobolshe{11.243,60.345,100.453,"For you"};
    class Box my_box(14.243,90.345,30.45,"for me");
    
    korobka.get_info();
    korobka.input(14.243,90.345,30.453);

    //korobka_pobolshe.input();
    
    korobka.get_info();
    korobka_pobolshe.get_info();
    korobka.set_width(102.1223);
    cout<<"new_width:"<<korobka.get_width()<<"\n";
    cout<<"Volume: "<<korobka.getVolume()<<"\n";
}