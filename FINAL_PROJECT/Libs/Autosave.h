#ifndef Autosave_H
#define Autosave_H

#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>


class Autosave{
    private:    
        std::string _path;

    public:
    Autosave(const std::string &path):_path(path){

    }
    void save(const int &charge,const int &time,const int &cash);
    void read(int *charge,int *time, int *cash);
    void clear();

};

#endif