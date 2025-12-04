#include<iostream>
#include<string.h>

using namespace std;

class Heal{
    public:
    void heal(){
        cout<<"Healing";
    }
    virtual ~Heal(){

    }
};

class Flying{
    public:
    virtual void fly() = 0;
    virtual ~Flying(){

    }
};
class swim{
    public:
    virtual void Swim() = 0;
    virtual ~swim(){
    }
};
class Character{
    public:
    virtual void attack()=0;
    virtual void move()=0;
    virtual string role()=0;
    virtual ~Character(){

    };
};
class Warrior:public Character,public swim{
    public:
    void attack()override{
        cout<<"Boom!";
    }
    void move()override{
        cout<<"Swap!";
    }
    string role()override{
        return "IDN";
    }
    void Swim()override{
        cout<<"Deep Dive";
    }
};

class magicue:public Character,public Flying,public Heal{
    public:
    void attack()override{
        cout<<"Magique!";
    }
    void move()override{
        cout<<"SwapMagic!";
    }
    string role()override{
        return "IDN";
    }
    
    void fly(){
        cout<<"He is flying in the clouds";
    }
};
int main(){
    Character *chars[3];
    chars[0] = new Warrior;
    chars[1] = new magicue;
    chars[2] = new Warrior;
    for(int i = 0;i<3;i++){
        cout<<"Character: "<<chars[i]->role()<<endl;
        chars[i]->move();
        chars[i]->attack();
        cout<<"========";
    }
    //chars[0]->Swim();
    for(int i =0;i<3;i++){
        delete chars[i];
    }
    Warrior war;
    war.Swim();
    magicue mar;
    mar.fly();
    mar.heal();
}