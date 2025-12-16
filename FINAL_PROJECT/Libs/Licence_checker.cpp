#include"Licence_checker.h"

bool Licence::check_license(){
    std::ifstream file_in(_path);
    while(file_in>>_buffer){
        if(_buffer[0] == 'L'){
            _buffer = _buffer.substr(2);
            if(_buffer == "BYPASS"){
                file_in.close();
                return 1;
            }
        }
    }
    file_in.close();
    return 0;
}

void Licence::create_license(){
    std::ofstream file_out(_path);
    file_out<<"L:BYPASS"<<std::endl;
    file_out<<"======= THANKS FROM AUTHOR ======="<<std::endl;
    file_out<<"Thank you for purchasing my products and supporting me"<<std::endl;
    file_out<<"Best regards! Code_Juggernaut"<<std::endl;
    file_out.close();
}
std::string Licence::get_license(){
    std::ifstream file_in(_path);
    if(!file_in.is_open()){
        Licence::create_license();
        return "Unable to find License.txt. Creating...";
    }
    std::string data;
    while(getline(file_in,_buffer)){
        data+=_buffer;
        data+='\n';
    }
    file_in.close();
    return data;
}