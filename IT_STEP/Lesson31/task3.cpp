#include<iostream>
#include<string.h>
using namespace std;

class Animal{
    private:
        string _name;
    protected:
        string _nik;
    public:
        
        Animal(const string &name, const string &nik)
        :_name(name),_nik(nik){

        }
        void speak(){
            cout<<"Animal sound-> "<<endl;
        }
        string getname()const{
            return _name;
        }
        string getnik() const{
            return _nik;
        }
};

class Fox:public Animal{
    public:
        Fox(const string &name, const string &nik)
        :Animal(name,nik){

        }
        void attack(){
            cout<<"Animal killed by "<<getname()<<" "<<getnik()<<" (fox)"<<endl;
        }
};

class Cat:protected Animal{
    public:
        Cat(const string &name, const string &nik)
        :Animal(name,nik){

        }
        void meow(){
            cout<<"MIAOW"<<endl;
            cout<<getname()<<endl;
            _nik = "Marine";
        }
};

class Tiger:public Cat{
    public:
    Tiger(const string &name, const string &nik)
        :Cat(name,nik){
    }
    void ROAR(){
        cout<<"ROAR"<<endl;
        cout<<getname()<<endl;
    }
};
class Parrot:private Animal{
    public:
        Parrot(const string &name, const string &nik)
        :Animal(name,nik){
    }
    void Speak(){
        cout<<"Hello! My name is"<<getname()<<endl;
    }
};

class Fish:public Animal{
    public:
        Fish(const string &name, const string &nik)
        :Animal(name,nik){
        }
        void Blob(){
            cout<<"blob lbolb"<<endl;
        }
};
class Ant:protected Animal{
    public:
        Ant(const string &name, const string &nik)
        :Animal(name,nik){
        }
        void bite(){
            cout<<getname()<<" "<<_nik<<" Is biting"<<endl;
        }
};
class Human:private Animal{
    public:
        Human(const string &name, const string &nik)
        :Animal(name,nik){
        }
        void Speak(){
            cout<<"Hello I'm intelligence. My name:"<<getname()<<endl;
        }
};
int main(){
    Fox fox("Charlie","The shadow");
    fox.attack();
    Cat cat("Henry","Pacifier");
    cat.meow();

    Tiger tiger("Roger","The fastest");
    tiger.meow();
    tiger.ROAR();
    Parrot parrot("Concord","the best");
    parrot.Speak();

    Fish fish("Ammy","drowned");
    fish.Blob();

    Human human("Mykola","Korostov");
    human.Speak();

    Ant ant("Barny","Jealuos");
    ant.bite();
}