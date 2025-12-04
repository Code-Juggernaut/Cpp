#include<iostream>
#include<string.h>

using namespace std;
/// @brief CHATGPT generated ENUM

class Pet{
    private:
        string _name;
        int _age;
        int _speed;
        enum Aggressiveness{ 
            CALM,            // Relaxed, friendly
            PLAYFUL,         // Energetic but not hostile
            CURIOUS,         // Investigative, alert but not aggressive
            DEFENSIVE,       // Protective, cautious
            IRRITATED,       // Annoyed, may growl or hiss
            AGGRESSIVE,      // Hostile, biting or scratching
            VERY_AGGRESSIVE,  // Extreme defensive attack (rare, usually fear-driven)
            UNDEFINED
        } _aggressive;
    protected:
        enum Aggressiveness str_to_enum(const string &aggressiveness ){
            if(aggressiveness == "calm")            return CALM;
            if(aggressiveness == "playful")         return PLAYFUL;
            if(aggressiveness == "curious")         return CURIOUS;
            if(aggressiveness == "defensive")       return DEFENSIVE;
            if(aggressiveness == "irritated")       return IRRITATED;
            if(aggressiveness == "aggressive")      return AGGRESSIVE;
            if(aggressiveness == "very_aggressive") return VERY_AGGRESSIVE;
            return UNDEFINED;
        }
        string enum_to_str()const {
            switch(_aggressive){
                case CALM:           return "\033[92m calm";break;
                case PLAYFUL:        return "\033[95m playful";break;
                case CURIOUS:        return "\033[94m curious";break;
                case DEFENSIVE:      return "\033[93m defensive";break;
                case IRRITATED:      return "\033[91m irritated";break;
                case AGGRESSIVE:     return "\033[91m aggressive";break;
                case VERY_AGGRESSIVE:return "\033[90m very aggressive";break;
                default:return "UNDEFINED";break;
            }
        }
    public:
        Pet(const string &name,const int age,const int speed,const string &aggressiveness):
        _name(name),_age(age),_speed(speed),_aggressive(str_to_enum(aggressiveness)){
            
        }
        void print_stats() const{
            cout<<"name: "<<_name<<endl;
            cout<<"age: "<<_age<<endl;
            cout<<"speed: "<<_speed<<" M/s"<<endl;
            cout<<"aggressiveness: "<<enum_to_str()<<endl;
            cout<<"\033[0m";
        }
        string get_name()const{
            return _name;
        }
        int get_age()const{
            return _age;
        }
        int get_speed()const{
            return _speed;
        }
};
class Parrot: public Pet{
    public:
    Parrot(const string &name,const int age,const int speed,const string &aggressiveness):
    Pet(name,age,speed,aggressiveness){

    }
    string get_class(){
        return "Parrot";
    }
};
class Dog:public Pet{
    public:
        Dog(const string &name,const int age,const int speed,const string &aggressiveness):
        Pet(name,age,speed,aggressiveness){

        }
        string get_class(){
            return "Dog";
        }
};
class Cat:public Pet{
    public:
    Cat(const string &name,const int age,const int speed,const string &aggressiveness):
    Pet(name,age,speed,aggressiveness){

    }
    string get_class(){
        return "Cat";
    }
};
class Fish:public Pet{
    public:
    Fish(const string &name,const int age,const int speed,const string &aggressiveness):
    Pet(name,age,speed,aggressiveness){

    }
    string get_class(){
        return "Fish";
    }
};

int main(){
    Parrot parrot("Charlie",3,2,"playful");
    parrot.print_stats();

    Dog dog("Bob",5,8,"calm");
    dog.print_stats();

    Cat cat("Marry",2,10,"irritated");
    cat.print_stats();

    Fish fish("Henry",1,1,"undefined");
    fish.print_stats();
}