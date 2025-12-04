#include<iostream>
#include<string.h>
using namespace std;

class Animal{
    private:
        char *_name;
        int sizeof_name;

        char *_sound;
        int sizeof_sound;

        char *_type;
        int sizeof_type;

    public:
        Animal(const string &name,const string &sound,const string &type){
            sizeof_name = name.size()+1;
            _name = new char[sizeof_name];
            for(int i = 0;i<sizeof_name;i++){
                _name[i] = name[i];
            }
            _name[sizeof_name] = '\n';
            

            sizeof_sound = sound.size()+1;
            _sound = new char[sizeof_sound];
            for(int i = 0;i<sizeof_sound;i++){
                _sound[i] = sound[i];
            }
            _sound[sizeof_sound] = '\n';
            
            sizeof_type = sound.size()+1;
            _type = new char[sizeof_type];
            for(int i = 0;i<sizeof_type;i++){
                _type[i] = type[i];
            }
            _type[sizeof_type] = '\n';
        }
        Animal(){
            _name = nullptr;
            _sound = nullptr;
            _type = nullptr;
        }
        void Sound(){
            cout<<_sound<<endl;
        }
        void Type(){
            cout<<_type<<endl;
        }
        void Name(){
            cout<<_name<<endl;
        }
        void print(){
            cout<<"Name: ";
            Name();
            cout<<"Sound: ";
            Sound();
            cout<<"Type: ";
            Type();
            cout<<endl;
        }
        virtual ~Animal(){
            delete[]_name;
            delete[]_type;
            delete[]_sound;
        }
};
class Parrot:public Animal{
    private:
        
    public:
        Parrot(const string &name):Animal(name,"Hello!","Parrot"){

        }
        ~Parrot(){
            Name();
            cout<<"deleted"<<endl;
        };
};
class Dog:public Animal{
    private:
        
    public:
        Dog(const string &name):Animal(name,"Wof","Dog"){

        }
        ~Dog(){
            Name();
            cout<<"deleted"<<endl;
        };
};

int main(){
    
    Parrot parrot("Mark");
    Animal **ptr = new Animal*[2];
    ptr[0] = new Dog("Polly");
    ptr[1] = new Parrot("Max");
    /* dog.print();
    parrot.print();*/

    for(int i =0 ;i<2;i++){
        ptr[i]->print();
    }
    for(int i = 0;i<2;i++){
        delete ptr[i];
    }
    delete[] ptr;
}