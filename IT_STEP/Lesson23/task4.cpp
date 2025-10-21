#include<iostream>
#include<stdio.h>
using namespace std;

int rand_weapon(){
    return rand()%3;
}

class Weapon{
    private:
    string _name;
    int _atk;
    int _ammo;
    public:
    void init(){
        cout<<"enter weapon stats:"<<endl;
        cout<<"Ammo:"<<endl;
        cin>>_ammo;
        cout<<"ATK:"<<endl;
        cin>>_atk;
        cout<<"Type:"<<endl;
        cin>>_name;
    }
    int shoot(){
        if(_ammo>0){
            _ammo--;
            return _atk;
        }
        return 0;
    }
    int getdmg(){
        return _atk;
    }
    string getname(){
        return _name;
    }
};

class Inventory{
    private:
        int _size;
        int *array;
    public:
        Inventory(int size):_size(size){
            array = new int[size];
            for(int i = 0;i<size;i++){
                array[i] = 0;
            }
            
        }
        ~Inventory(){
            delete[] array;
        }

        int use(int itempos){
            int temp = array[itempos];
            array[itempos] = 0;
            return temp;
        }
        void add(int itempos, int itemtype){
            array[itempos] = itemtype;
        }
        void auto_fill(){
            for(int i = 0;i<_size;i++){
                array[i] = rand()%10;
            }
        }
        int get_name(int pos){
            return array[pos];
        }
};

class Player{
    private:
        int _inventory_size;
        Inventory *pointer;
        Weapon *Weaponpointer[3];
        int _atk;
        int _def;
        int health;
    public:
        Player(int inventory_size,int atk,int def):_inventory_size(inventory_size),_atk(atk),_def(def){
            pointer = new Inventory(inventory_size);
            for(int i = 0;i<3;i++){
                Weaponpointer[i] = new class Weapon;
                Weaponpointer[i]->init();
            }
            health = 100;
            pointer->auto_fill();
        };
        ~Player(){
            delete pointer;
            for(int i = 0;i<3;i++){
                delete Weaponpointer[i];
            }
        }
        float dealdamage(int type){
            cout<<"using"<<Weaponpointer[type]->getname()<<endl;
            return _atk * (Weaponpointer[type]->shoot());
        }
        void take_damage(int dmg){
            health -= dmg/_def;
        }
        int is_alive(){
            return health>=0?1:0;
        }
        void print_stats(){
            cout<<"HP:"<<health<<endl;
            cout<<"ATK:"<<_atk<<endl;
            cout<<"DEF:"<<_def<<endl;
            cout<<"Items:"<<endl;
            for(int i = 0;i<_inventory_size;i++){
                switch(pointer->get_name(i)){
                    case 0:break; 
                    case 1:cout<<"Iron Skin potion";break;
                    case 2:cout<<"Potion of Fury";break;
                    case 3:cout<<"Poison XD";break;
                    case 4:cout<<"Healing potion";break;
                }
                cout<<endl;
            }
            cout<<endl;
        }
        void use_random_item(){
            int buff = pointer->use(rand()%_inventory_size);
            switch(buff){
                case 0:break; 
                case 1:_atk += 100;cout<<"used Potion of Fury";break;
                case 2:_def += 100;cout<<"used Iron Skin potion";break;
                case 3:health -= 5;cout<<"used Poison XD";break;
                case 4:health += (health<100)?(5):(0);cout<<"used Healing potion";break;
            }
            cout<<endl;
        }
};

int main(){
    Player pl1(10,20,100);
    Player pl2(5,25,60);
    while(pl1.is_alive()&&pl2.is_alive()){
        float dmg = pl1.dealdamage(rand_weapon());
        pl2.take_damage(dmg);
        pl1.print_stats();
        pl2.print_stats();
        pl1.use_random_item();
        pl2.use_random_item();
    }
}