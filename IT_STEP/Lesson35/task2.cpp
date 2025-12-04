#include<iostream>
#include<memory>
#include<string>

using namespace std;

class Warrior{
    string _name;
    int _strength;
    public:
        Warrior(const string &name,const int strength):_name(name),_strength(strength){
            cout<<_name<<" created with strength "<<_strength<<'\n';
        }
        ~Warrior(){
            cout<<_name<<" Died\n";
        }
        void attack()const{
            cout<<_name<<" attacks & deals "<<_strength<<" dmg\n";
        }
        string getname()const{
            return _name;
        }
};

class Statistics{
    private:
        weak_ptr<Warrior> observers[2];
    public:
        void register_value(shared_ptr<Warrior> warrior, int index){
            if(index>=0 && index<2){
                observers[index]= warrior;
            }
        }
        void report()const{
            for(int i = 0;i<2;i++){
                if(auto warrior = observers[i].lock()){
                    cout<<"still alive"<<warrior->getname()<<endl;
                }else{
                    cout<<"Dead>=)"<<endl;
                }
            }
        }
};


int main(){
    shared_ptr<Warrior> player = make_shared<Warrior>("Mark-II",10);
    shared_ptr<Warrior> enemy = make_shared<Warrior>("Destroyer-II",70);
    
    player->attack();
    enemy->attack();
    Statistics stats;
    {
        shared_ptr<Warrior> player = make_shared<Warrior>("Mark-II",10);
        shared_ptr<Warrior> enemy = make_shared<Warrior>("Destroyer-II",70);

        stats.register_value(player,0);
        stats.register_value(enemy,1);
        player->attack();
        enemy->attack();
        stats.report();
    }
    shared_ptr<Warrior> copy(player);
    cout<<player->getname()<<'\n';
    cout<<copy->getname()<<'\n';
    cout<<endl<<"========results========"<<endl;
    stats.report();

}