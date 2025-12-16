#include"Autosave.h"
void Autosave::save(const int &charge,const int &time,const int &cash){
    std::ofstream file_out(_path);
    file_out<<std::fixed<<std::setprecision(2)<<charge<<std::endl;
    file_out<<time<<std::endl<<cash<<std::endl;
    file_out.close();
    }
void Autosave::read(int *charge,int *time, int *cash){
    std::ifstream file_in(_path);
    file_in>>(*charge)>>(*time)>>(*cash);
    if((*charge)>110){
        (*charge) = 0;
    }
    file_in.close();
}
void Autosave::clear(){
    std::ofstream file_out(_path);
    file_out<<std::endl;
    file_out.close();
}