#include<iostream>
#include<cstring>
using namespace std;
class person{

    public:
        person(int ages, int healths, int damages,int def,string names){
            age = ages;
            health = healths;
            damage = damages;
            defence = def;
            name = names;
        }
        void damage_take(int damage){
            health -= damage-defence;
            if(health<=0){
                cout<<"\033[91m"<<name<<" defeated\n";
            }
        }
        int damage_deal(){
            return damage;

        }
        void print_status(){
            cout<<"Class:"<<name<<"\n";
            cout<<"age:"<<age<<"years\n";
            cout<<"health:"<<health<<"hp\n";
            cout<<"damage:"<<damage<<"hp\n";
            cout<<"defence:"<<defence<<"\n";
            
        }
        void heal(){
            if(health<2000){
                health+=30;
            }else{
                cout<<"max health";
            }
        }
        int get_hp(){
            return health;
        }
    private:
        int age;
        int health;
        int damage;
        int defence;
        string name;
};
person player(30,100,20,2,"user");
person enemy(2340,224,42,43,"enemy");

int main(){
    cout<<"Enemy arrived\n";
    while(player.get_hp()>0 && enemy.get_hp()){
        player.print_status();
        if(enemy.get_hp()>=0){
            cout<<"Enemy Attacks!\n";
            player.damage_take(enemy.damage_deal());
        }else{
            break;
        }

        if(player.get_hp()>=0){
            enemy.print_status();
            cout<<"Player Attacks\n";
            enemy.damage_take(player.damage_deal());
        }else{
            
            cout<<"\033[91m Game over\n";
            cout<<"\033[93m--- Death Log ---\n";
            player.print_status();
            break;
        }
    }
    if(enemy.get_hp()>0){
        cout<<"\033[91mEnemy win";
    }else{
        cout<<"\033[93mPlayer win";
    }
}