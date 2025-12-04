#include<iostream>
#include<string.h>

using namespace std;

class Shape{
    private:
        char *name;
    public:
    virtual string get_type()const{
        return "shape";
    }
    virtual double get_area()const{
        return 0.00;
    }
    ~Shape(){   
        delete[] name;
        cout<<"Shape deleted!";
    }
};

class Circle:public Shape{
    private:
        double _rad;
        char *test;
    public:
        Circle(double rad):_rad(rad){

        }
    string get_type()const{
        return "Circle";
    }
    double get_area()const{
        return 3.1415*_rad*_rad;
    }
    ~Circle(){
        delete[] test;
        cout<<"Circle deleted!";
    }
};

class Rectangle:public Shape{
    private:
        double _width;
        double _height;
        char *test;
    public:
        Rectangle(double width,double height):
        _width(width),_height(height){

        }
    string get_type()const{
        return "Rectangle";
    }
    double get_area()const{
        return _width*_height;
    }
    ~Rectangle(){
        delete[] test;
        cout<<"Rectangle deleted!";
    }
};
class Square: public Rectangle{
    private:
        double _size;
        char *test;
    public:
        Square(int size):Rectangle(size,size),_size(size){

        }

        string get_type()const{
            return "Square";
        }
        double get_area()const{
            return _size*_size;
        }
        ~Square(){
            delete[] test;
            cout<<"Square deleted!";
        }
};
void print_shape_area(Shape *obj){
    cout<<"area: "<<obj->get_area()<<" type:"<<obj->get_type()<<endl;
}

int main(){
    /*Circle circle(100);
    Rectangle rect(2,10);

    Circle array[10]{Circle(13.0),Circle(45.0),Circle(32.0),Circle(22.0),Circle(54.0),Circle(24.0),Circle(23.0),Circle(32.0),Circle(12.0),Circle(10.0)};
    Shape *test[6]{new Circle(13.0),new Circle(45.0),new Rectangle(32.0,10),new Rectangle(22.0,9.1),new Square(9.05),new Square(19.05)};
    
    /*cout<<circle.get_type()<<" "<<circle.get_area()<<endl;
    cout<<rect.get_type()<<" "<<rect.get_area()<<endl;
    
    
    print_shape_area(&circle);
    print_shape_area(&rect);
    

    for(Shape &obj: array){
        cout<<obj.get_area()<<" "<<obj.get_type()<<endl;
    }
    for(Shape *obj: test){
        cout<<obj->get_area()<<" "<<obj->get_type()<<endl;
        delete obj;
    }*/


    Circle circle(10);
    Circle *pointer = new Circle(5);
    delete pointer;
    Shape *ptr = new Circle(10);
    delete ptr;
}