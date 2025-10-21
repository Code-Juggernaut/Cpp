#include<iostream>
#include<string.h>
using namespace std;

class task{
    private:
        string _description;
    public:
        task(const string &description):_description(description){

        };
        void show(){
            cout<<"task: "<<_description<<endl;
        }
};

class taskmanager{
    static const int MAXTASKS = 5;
    task *pointer[MAXTASKS];
    int task_count;
    public: 
        taskmanager(int task = 0):task_count(task){

        }
        void create_task(task *task){
            if(task_count<MAXTASKS){
                pointer[task_count++]= task;
            }else{
                cout<<"Buffer full"<<endl;
            }
        }
        void print_task(){
            cout<<"current_tasks:";
            for(int i = 0;i<task_count;i++){
                pointer[i]->show();
            }
        }
};

int main(){
    task task1("create class))");
    task task2("create main))");
    task task3("run!!!))");

    taskmanager manager ;
    manager.create_task(&task1);
    manager.create_task(&task2);
    manager.create_task(&task3);
    manager.print_task();
}