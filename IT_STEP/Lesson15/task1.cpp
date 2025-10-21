#include<iostream>
#include<string.h>

using std::cout;
using std::string;

enum type{
    NAME,CLASS,ATTR,SOUND,COLOR  
};
class data{
    
    private:
        string _name;
        string _class;
        string _attribute;
        string _sound;
        string _color;
    public:

    data(string name,string clas,string attribute,string sound,string color){
        _name = name;
        _class = clas;
        _attribute = attribute;
        _sound = sound;
        
        _color = color;
        
    };

    void getinfo(){
        cout<<'\n'<<_color;
        cout<<"Name "<<_name<<'\n';
        cout<<"Class "<<_class<<'\n';
        cout<<"attr "<<_attribute<<'\n';
        cout<<"Voice "<<_sound<<'\n';
    }
    void reset_info(enum type type,string data){
        switch(type){
            case NAME:_name = data;break;
            case CLASS:_class = data;break;
            case SOUND:_sound = data;break;
            case ATTR:_attribute = data;break;
            case COLOR:_color = data;break;
        }
    }   
};
data Animal_primate ("Shkolnik","Primate","dummy","Da ty cho?","\033[91m");
data Animal_wolf("wolf","hunter","archy","Woof","\033[94m");
data Animal_dog("Dog","pet","Kairo","Bark","\033[97m");

int main(){
    cout<<"\033[92m";
    Animal_primate.getinfo();
    Animal_wolf.getinfo();
    Animal_dog.getinfo();
    Animal_primate.reset_info(NAME,"Monkey");
    Animal_primate.reset_info(ATTR,"kotlin");
    Animal_primate.reset_info(SOUND,"yaaa");
    Animal_primate.getinfo();

}