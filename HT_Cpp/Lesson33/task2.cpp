#include<iostream>
#include<fstream>
#include<ios>

using namespace std;

/**
 * NOTE: 
 * https://refactoring.guru/ru
 * 
 * CAUTION:
 * Custom file parser implemented!
 * struct : Object(E/R/C/S) _x _y _sizex _sizey(Only on Ellipse and Rectangle);
 * 
 * TODO:
 * just run program, it will create file with '0' values
 * 
 * TEST:
 * 
 * E 10 50 60 90
 * R 10 20 50 60
 * S 20 30 70
 * C 60 10 40
 */

class Object{
    public: 
        virtual void read(const string &filename) = 0;
        virtual void save(const string &filename)const = 0;
        virtual void show()const = 0;
};

class Square:public Object{
    private:
        int _x;
        int _y;
        int _length;
    public:
        Square(const int x, const int y, const int length):_x(x),_y(y),_length(length){

        }
        void read(const string &filename)override{
            ifstream file_in(filename);
            char label = ' ';
            while(file_in>>label && label != 'S'){
                
            }
            file_in>>_x>>_y>>_length;
            file_in.close();
        }
        void save(const string &filename)const override{
            ofstream file_out(filename,std::ios::app);
            file_out<<"S "<<_x<<" "<<_y<<" "<<_length<<endl;
            file_out.close();
        }
        void show()const override{
            cout<<"Square"<<endl;
            cout<<"(x:y)"<<_x<<" "<<_y<<endl;
            cout<<"size: "<<_length<<endl;
        }

};
class Rectangle:public Object{
    private:
        int _x;
        int _y;
        int _sizex;
        int _sizey;
    public:
        Rectangle(const int x, const int y, const int sizex,const int sizey):
        _x(x),_y(y),_sizex(sizex),_sizey(sizey){

        }
        void read(const string &filename)override{
            ifstream file_in(filename);
            char label = ' ';
            while(file_in>>label && label != 'R'){
                
            }
            file_in>>_x>>_y>>_sizex>>_sizey;
            file_in.close();
        }
        void save(const string &filename)const override{
            ofstream file_out(filename,std::ios::app);
            file_out<<"R "<<_x<<" "<<_y<<" "<<_sizex<<" "<<_sizey<<endl;
            file_out.close();
        }
        void show()const override{
            cout<<"Rectangle"<<endl;
            cout<<"(x:y)"<<_x<<" "<<_y<<endl;
            cout<<"(sizex:sizey): "<<_sizex<<" "<<_sizey<<endl;
        }
};
class Circle:public Object{
    private:
        int _x;
        int _y;
        int _rad;
    public:
        Circle(const int x, const int y, const int rad):_x(x),_y(y),_rad(rad){

        }
        void read(const string &filename)override{
            ifstream file_in(filename);
            char label = ' ';
            while(file_in>>label && label != 'C'){
                
            }
            file_in>>_x>>_y>>_rad;
            file_in.close();
        }
        void save(const string &filename)const override{
            ofstream file_out(filename,std::ios::app);
            file_out<<"C "<<_x<<" "<<_y<<" "<<_rad<<endl;
            file_out.close();
        }
        void show()const override{
            cout<<"Circle"<<endl;
            cout<<"(x:y)"<<_x<<" "<<_y<<endl;
            cout<<"Radius: "<<_rad<<endl;
        }
};
class Ellipse:public Object{
    private:
        int _x;
        int _y;
        int _sizex;
        int _sizey;
    public:
        Ellipse(const int x, const int y, const int sizex,const int sizey):
        _x(x),_y(y),_sizex(sizex),_sizey(sizey){

        }
        void read(const string &filename)override{
            ifstream file_in(filename);
            char label = ' ';
            while(file_in>>label && label != 'E'){

            }
            file_in>>_x>>_y>>_sizex>>_sizey;
            file_in.close();
        }
        void save(const string &filename)const override{
            ofstream file_out(filename,std::ios::app);
            file_out<<"E "<<_x<<" "<<_y<<" "<<_sizex<<" "<<_sizey<<endl;
            file_out.close();
        }
        void show()const override{
            cout<<"Rectangle"<<endl;
            cout<<"(x:y)"<<_x<<" "<<_y<<endl;
            cout<<"(sizex:sizey): "<<_sizex<<" "<<_sizey<<endl;
        }

};

int main(){
    Object **object = new Object*[4];

    object[0] = new Ellipse(0,0,0,0);
    object[1] = new Rectangle(0,0,0,0);
    object[2] = new Square(0,0,0);
    object[3] = new Circle(0,0,0);
    for(int i = 0;i<4;i++){
        object[i]->read("Files.dat");
    }
    ofstream("Files.dat",std::ios::trunc);

    
    
    for(int i = 0;i<4;i++){
        object[i]->show();
        object[i]->save("Files.dat");
    }
    delete[] object;
}