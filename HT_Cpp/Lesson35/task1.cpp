#include<iostream>
#include<string>
#include<memory>
/**
 * NOTE:
 * https://metanit.com/cpp/tutorial/11.1.php
 */
using namespace std;

class Weapon{
    private:
        string _name;
        int _dmg;
    public:
        Weapon(const string &name,const int dmg):_name(name),_dmg(dmg){

        }

        Weapon():_dmg(0),_name(" "){

        }
        void attack()const{
            cout<<"Dealing "<<_dmg<<" dmg from"<<_name<<endl;
        }
};

int main(){
    
    unique_ptr markvii = make_unique<Weapon>("MARK-VII",102);
    unique_ptr ak47 = make_unique<Weapon>("AK-47",21);
    unique_ptr avp = make_unique<Weapon>("AVP",200);
    unique_ptr bfg10k= make_unique<Weapon>("BFG-10K",120);
    unique_ptr m4 = make_unique<Weapon>("M4",30);

    unique_ptr<Weapon> current = move(markvii);
    current->attack();

    current = move(ak47);
    current->attack();

    current = move(avp);
    current->attack();
}