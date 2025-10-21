#include<iostream>
#include<filesystem>
#include<fstream>

using namespace std;
using namespace std::filesystem;

void show_current_dir(){
    cout<<"your dir is: "<<current_path()<<'\n';
}
void change_dir(const string &path){
    try{
        current_path(path);
    } catch(...){
        cout<<"ERROR dir not found";
    }
    
}

void create_dir(const string &_path){
    path dir_path = _path;
    create_directories(dir_path);
}
void delete_dir(const string &_path){
    path dir_path = _path;
    remove_all(dir_path);
}
void list_dir(){
    for(const auto& entry : recursive_directory_iterator(current_path())){
        if(entry.is_directory()){
            cout<<" -> "<<entry.path().filename()<<'\n';
        }
    }
}
void list_file(){
    for(const auto& entry : recursive_directory_iterator(current_path())){
        if(entry.is_regular_file()){
            cout<<" _> "<<entry.path().filename()<<'\n';
        }
    }
}
int main(){
    string dir = "a/b/c";
    show_current_dir();
    list_dir();
    list_file();
    create_dir(dir);
    delete_dir("a");
    change_dir("P:\\");
    
    
    show_current_dir();
    path volume_dir = "P:\\";
    auto space_inform = space(volume_dir);
    cout<<"Free space on Volume 'P': "<<space_inform.free<<" bytes"<<"\n";
    auto total_space = space(volume_dir);
    cout<<"Total space on Volume 'P': "<<total_space.capacity<<" bytes"<<"\n";

}   