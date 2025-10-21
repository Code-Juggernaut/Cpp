#include<iostream>
#include<fstream>
#include<filesystem>
#include<string.h>
using namespace std;
using namespace std::filesystem;

path handle_cmd(char *command,char *argument,string filename){
    path current = current_path();
    char operation = ' ';
    char arg = argument[1];

    if(!strcmp(command,"rm")){
        operation = 'r';
    }else if(!strcmp(command,"cd")){
        operation = 'c';
    }else if(!strcmp(command,"ls")){
        operation = 'l';
    }else if(!strcmp(command,"ad")){
        operation = 'a';
    }else{
        cout<<"INVALID COMMAND";return current;
    }

    switch(operation){
        case 'a':{
            switch(arg){
                case 'd': create_directory(current/filename);break;
                case 'f': ofstream new_file(current/filename);new_file.close();break;
            }
        };break;
        case 'r':{
            switch(arg){
                case 'd': remove_all(current/filename);break;
                case 'f': remove(current/filename); break;
                case 'a': 
                    for(const auto &entity : directory_iterator(current_path())){
                        if(entity.is_directory()){
                            remove_all(entity);
                        }
                    }break;
                }
        };break;
        case 'c':{
            current_path(filename);
            return current_path();
        };break;
        case 'l':{
            for(const auto &entity: recursive_directory_iterator(current_path())){
                switch(arg){
                    case 'd': if(entity.is_directory()){cout<<" -> "<<entity.path().filename()<<'\n';}break;
                    case 'f': if(entity.is_regular_file()){cout<<" -> "<<entity.path().filename()<<'\n';}break;
                    case 'a': if(entity.is_directory() || entity.is_regular_file()){cout<<" -> "<<entity.path().filename()<<'\n';}break;
                }
            }
        }
    }
    return current;
}


int main(){
    char command[3];
    char argument[3];
    string filename;
    path filepath = "W:\\";
    cout<<"Welcome to SFM(Simple File Manager)!\n";
    recursive:
    cout<<"you are at:"<<current_path()<<"\n";
    cout<<"enter command(cd/ls/rm/ad/ex):";
    for(int i = 0;i<2;i++){
        cin>>command[i];
    }
    cout<<"enter argument(-d/-a/-f(useless at cd)):";
    for(int i = 0;i<2;i++){
        cin>>argument[i];
    }
    if(!strcmp(command,"ex")){
        cout<<"program end";
        return 0;
    }
    cout<<"enter filename(useless in some cases, so just type NAN at cd/ls):";
    string file;
    cin>>file;
    filepath = handle_cmd(command,argument,file);
    goto recursive;
}