#include<iostream>
#include<math.h>
#include<time.h>
#include<chrono>
#include<thread>


using namespace std;

struct Linear_move{
    int move(int x,int frame) const{
        return x+2;
    }
};

struct Wave_move{
    int move(int x,int frame) const{
        return x+static_cast<int>(1.5*sin(frame*0.3));
    }
};

struct Circular_move{
    int move(int x,int frame) const{
        return x+static_cast<int>(40+10*cos(frame*0.2));
    }
};
struct Red_color{
    void setcolor() const{
        cout<<"\033[91m";
    }
};

struct Green_color{
    void setcolor() const {
        cout<<"\033[92m";
    }
};

struct Blue_color{
    void setcolor() const {
        cout<<"\033[94m";
    }
};

struct Blind_color{
    void setcolor() const{
        
    }
};

struct Vampire{
    void draw(int x) const{
        cout<<string(x,' ')<<R"(//^\\)"<<endl;
        cout<<string(x,' ')<<R"(o-o)"<<endl;
        cout<<string(x,' ')<<R"(/|^|\)"<<endl;
        cout<<string(x,' ')<<R"(_/ \_)"<<endl;
    }
};
struct Spider{
    void draw(int x) const{
        cout<<string(x,' ')<<R"(\|/)"<<endl;
        cout<<string(x,' ')<<R"( o)"<<endl;
        cout<<string(x,' ')<<R"(/|\)"<<endl;
        cout<<string(x,' ')<<R"(_/ \_)"<<endl;
    }
};

struct Turret{
    void draw(int x) const{
        cout<<string(x,' ')<<R"(   /-\)"<<endl;
        cout<<string(x,' ')<<R"(* /   \ *)"<<endl;
        cout<<string(x,' ')<<R"(|-| o |-|)"<<endl;
        cout<<string(x,' ')<<R"(* \   / *)"<<endl;
        cout<<string(x,' ')<<R"(   \-/)"<<endl;
        cout<<string(x,' ')<<R"(    |)"<<endl;
        cout<<string(x,' ')<<R"(   /|\)"<<endl;
    }
};


template <typename Graphics,typename Motion, typename Color>

class Mon3tr{
    private:
        int pos;
        int frame;
        Graphics GL;
        Motion MT;
        Color CL;
    public:
    Mon3tr(){
        pos = 0;
        frame = 0;

    }
    void update(){
        pos = MT.move(pos,frame);
        frame++;
        if(frame>10){
            frame = 0;
        }
        
        CL.setcolor();
        GL.draw(pos);
        cout<<"\033[0m";
    }
};  



int main(){
    Mon3tr <Vampire,Circular_move,Red_color>obj1;
    

    Mon3tr <Spider,Wave_move,Green_color>obj2;
    Mon3tr <Turret,Linear_move,Blue_color> obj3;
    while(1){
        system("clear");
        obj1.update();
        obj2.update();
        obj3.update();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}