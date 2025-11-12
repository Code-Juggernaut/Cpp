#include<iostream>
#include<filesystem>
#include<fstream>

using namespace std;
using namespace std::filesystem;
int main(){
    path mydir = "mydir";
    if(!exists(mydir)){
        create_directory(mydir);
        cout<<"dir not found, creating new dir";
    }
    path myfile = mydir / "myfile.txt"; 
    ofstream file(myfile);
    if(file.is_open()){
        file<<"Hello World";
        file.close();
        cout<<"file_created";
    }else{
        cout<<"handle_error";
    }
}