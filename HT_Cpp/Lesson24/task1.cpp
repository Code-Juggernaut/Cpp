#include<iostream>
#include<string.h>

using namespace std;

class Reservoir{
    private:
        char *_name;
        int namelen;
        float _width;
        float _height;
        float _depth;
    public:
    //======================= CONSTRUCTORS ========================
        explicit Reservoir(){
            _name = new char[1];
            _width = 0;
            _height = 0;
            _depth = 0;
        }
        explicit Reservoir(const char *name,float width,float height, float depth):_width(width),_height(height),_depth(depth){
            namelen = strlen(name);
            _name = new char[namelen+1];
            strcpy(_name,name);
        }
        Reservoir(const class Reservoir &copy){
            namelen = copy.namelen;
            _width = copy._width;
            _height = copy._height;
            _depth = copy._depth;
            _name = new char[namelen+1];
            strcpy(_name,copy._name);
        }
        Reservoir &operator=(const class Reservoir other){
            if(this == &other){
                return *this;
            }
            delete[] _name;
            namelen = other.namelen;
            _name = new char[namelen+1];
            strcpy(_name,other._name);
            return *this;
        }
        
        bool operator<(const class Reservoir &other) const { // chatGPT fix
            return (this->_width*this->_height) < (other._width*other._height);
        }
        ~Reservoir(){
            cout<<"deleted "<<this->_name<<endl;
            delete[] _name;
        }
        
        //======================== FUNCTIONS =================
        float find_volume(){
            return _width*_height*_depth;
        }
        class Reservoir copy(){
            class Reservoir _new(this->_name,this->_width,this->_height,this->_depth);
            return _new;
        }
        void print() const{
            cout<<"Name:"<<_name<<"m"<<endl;
            cout<<"width:"<<_width<<"m"<<endl;
            cout<<"height:"<<_height<<"m"<<endl;
            cout<<"depth:"<<_depth<<"m"<<endl;
        }
        void reinit(){
            cout<<"enter new values(width height depth):";
            cin>>_width>>_height>>_depth;
            string new_name;
            cout<<"enter new name";
            cin>>new_name;
            delete[]_name;
            namelen = new_name.size();
            _name = new char[namelen+1];
            strcpy(_name,new_name.c_str()); // tiny focus)))
        }
        const char* getname(){
            return _name;
        }
    };      

int main(){
    class Reservoir object1("Marian's_depth",100,200,6000);
    class Reservoir object2;
    bool is_exceed;
    object2 = object1.copy();
    object1.print();
    object1.copy();
    object1.find_volume();
    object2.reinit();
    object2.print();
    is_exceed = object1<object2;
    cout<<((is_exceed==1)?(object1.getname()):(object2.getname()))<<"<"<<((is_exceed==0)?(object1.getname()):(object2.getname()))<<endl;
}