#ifndef Licence_checker_H
#define Licence_checker_H

#include<fstream>
#include<string>

class Licence{
    private:
        std::string _buffer;
        std::string _path;
    public:
        Licence(const std::string &path):_path(path){

        }
        bool check_license();
        void create_license();
        std::string get_license();
        
};



#endif