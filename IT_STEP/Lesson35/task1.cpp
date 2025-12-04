#include<iostream>
#include<memory>

using namespace std;

struct Enemy{
    Enemy(){
        cout<<"Something created"<<endl;
    }
    ~Enemy(){
        cout<<"Something deleted"<<endl;
    }
    void attack()const {
        cout<<"Enemy attacking! Watch out!"<<endl;
    }

};

int main(){
    unique_ptr<Enemy> boss = make_unique<Enemy>();
    boss->attack();
    unique_ptr<Enemy> new_boss = move(boss);
    if(!boss){
        cout<<"Moved\n";
    }
    boss->attack();
    new_boss->attack();
}