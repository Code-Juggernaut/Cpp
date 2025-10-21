#include<iostream>
#include<string.h>
#include<stdio.h>
#include<fstream>

using namespace std;

string filename;

class Abonent{
    private:
        char *_name;
        int namelen;

        char *_mobile_phone;
        int m_phonelen;

        char *_home_phone;
        int h_phonelen;

        char *_fax;
        int faxlen;

        char *_additional_info;
        int add_infolen;
        char* reallocate(char *array, int *size,int new_size){
            char *new_array = new char[new_size];
            for(int i = 0;i<((*size)<new_size?(*size):(new_size));i++){
                new_array[i] = array[i];
            }
            (*size) = new_size;
            new_array[new_size-1] = '\0';
            delete[] array;
            return new_array;
        }
        void copy(char *from,char *to,int size){
            for(int i = 0;i<size;i++){
                to[i] = from[i];
            }
        }
    public:
        //============================= CONSTRUCTORS =======================
        Abonent(const char *name, const char *mobile_phone,const char *home_phone, const char *fax, const char *add_info){
            namelen = strlen(name)+1;
            _name = new char[namelen];
            strcpy(_name,name);

            m_phonelen = strlen(mobile_phone)+1;
            _mobile_phone = new char[m_phonelen];
            strcpy(_mobile_phone,mobile_phone);

            h_phonelen = strlen(home_phone)+1;
            _home_phone = new char[h_phonelen];
            strcpy(_home_phone,home_phone);

            faxlen = strlen(fax)+1;
            _fax = new char[faxlen];
            strcpy(_fax,fax);

            add_infolen = strlen(add_info)+1;
            _additional_info = new char[add_infolen];
            strcpy(_additional_info,add_info);
        }
        Abonent(){
            namelen =1;
            _name = new char[namelen];

            m_phonelen =1;
            _mobile_phone = new char[m_phonelen];

            h_phonelen = 1;
            _home_phone = new char[h_phonelen];

            faxlen = 1;
            _fax = new char[faxlen];

            add_infolen = 1;
            _additional_info = new char[add_infolen];
        }
        //>_ CHATGPT FIX START
        Abonent(const Abonent &pointer){
            cout<<"Copying...";
            namelen = strlen(pointer._name)+1;
            _name = new char[namelen];
            strcpy(_name,pointer._name);

            m_phonelen = strlen(pointer._mobile_phone)+1;
            _mobile_phone = new char[m_phonelen];
            strcpy(_mobile_phone,pointer._mobile_phone);

            h_phonelen = strlen(pointer._home_phone)+1;
            _home_phone = new char[h_phonelen];
            strcpy(_home_phone,pointer._home_phone);

            faxlen = strlen(pointer._fax)+1;
            _fax = new char[faxlen];
            strcpy(_fax,pointer._fax);

            add_infolen = strlen(pointer._additional_info)+1;
            _additional_info = new char[add_infolen];
            strcpy(_additional_info,pointer._additional_info);
        }
        Abonent& operator=(const Abonent& other) {
    if (this == &other) return *this; // self-assignment check

    // Free existing resources
    delete[] _name;
    delete[] _mobile_phone;
    delete[] _home_phone;
    delete[] _fax;
    delete[] _additional_info;

    // Copy new resources
    namelen = strlen(other._name) + 1;
    _name = new char[namelen];
    strcpy(_name, other._name);

    m_phonelen = strlen(other._mobile_phone) + 1;
    _mobile_phone = new char[m_phonelen];
    strcpy(_mobile_phone, other._mobile_phone);

    h_phonelen = strlen(other._home_phone) + 1;
    _home_phone = new char[h_phonelen];
    strcpy(_home_phone, other._home_phone);

    faxlen = strlen(other._fax) + 1;
    _fax = new char[faxlen];
    strcpy(_fax, other._fax);

    add_infolen = strlen(other._additional_info) + 1;
    _additional_info = new char[add_infolen];
    strcpy(_additional_info, other._additional_info);

    return *this;
}
        //>_CHATGPT FIX END
        //============================= DESTRUCTORS =======================
        ~Abonent(){
            cout<<"deleted";
            delete []_name;
            delete []_home_phone;
            delete []_mobile_phone;
            delete []_fax;
            delete []_additional_info;
        }
        //============================= FUNCTIONS =========================
        void print_info(){
            cout<<"Name: "<<_name<<endl;
            cout<<"Mobile phone: "<<_mobile_phone<<endl;
            cout<<"Home phone: "<<_home_phone<<endl;
            cout<<"Fax: "<<_fax<<endl;
            cout<<"Additional info: "<<_additional_info<<endl;
        }
        char *get_info(char type, int *size){
            switch(type){
                case 'N': (*size) = namelen; return _name; break;
                case 'M': (*size) = m_phonelen; return _mobile_phone; break;
                case 'H': (*size) = h_phonelen; return _home_phone; break;
                case 'F': (*size) = faxlen; return _fax; break;
                case 'I': (*size) = add_infolen; return _additional_info; break;
            }
        }
        void edit_info(char operand){
            
            int temp_size = 1;
            char *buffer = new char[temp_size];
            buffer[0] = ' ';
            while(buffer[temp_size-1]!= '|'){
                scanf(" %c",&buffer[temp_size-1]);
                if(buffer[temp_size-1]!='|'){
                    buffer = reallocate(buffer,&temp_size,temp_size+1);
                }
            }
            buffer[temp_size-1] = '\0';
            switch(operand){
                case 'N': cout<<"enter name:";_name = reallocate(_name,&namelen,temp_size);copy(buffer,_name,temp_size);break; 
                case 'M': cout<<"enter mobile phone:";_mobile_phone = reallocate(_mobile_phone,&m_phonelen,temp_size);copy(buffer,_mobile_phone,temp_size);break; 
                case 'H': cout<<"enter home phone:";_home_phone = reallocate(_home_phone,&h_phonelen,temp_size);copy(buffer,_home_phone,temp_size);break; 
                case 'F': cout<<"enter fax:";_fax = reallocate(_fax,&faxlen,temp_size);copy(buffer,_fax,temp_size);break;
                case 'I': cout<<"enter additional info:";_additional_info = reallocate(_additional_info,&add_infolen,temp_size);copy(buffer,_additional_info,temp_size);break;
            }
        }
        
        //============================ FILE OPERATIONS =======================
        void read_from_file(ifstream *file){
            
            delete[] _name;
            delete[] _mobile_phone;
            delete[] _home_phone;
            delete[] _fax;
            delete[] _additional_info;
            *file>>namelen;
            namelen++;
            _name = new char[namelen];
            for(int i = 0;i<namelen;i++){
                *file>>_name[i];
            }
            _name[namelen-1] = '\0';

            *file>>m_phonelen;
            m_phonelen++;
            _mobile_phone = new char[m_phonelen];
            for(int i = 0;i<m_phonelen;i++){
                *file>>_mobile_phone[i];
            }
            _mobile_phone[m_phonelen-1] = '\0';

            *file>>h_phonelen;
            h_phonelen++;
            _home_phone = new char[h_phonelen];
            for(int i = 0;i<h_phonelen;i++){
                *file>>_home_phone[i];
            }
            _home_phone[h_phonelen-1]= '\0';
            
            *file>>faxlen;
            faxlen++;
            _fax = new char[faxlen];
            for(int i = 0;i<faxlen;i++){
                *file>>_fax[i];
            }
            _fax[faxlen-1] = '\0';

            *file>>add_infolen;
            add_infolen++;
            _additional_info = new char[add_infolen];
            for(int i = 0;i<add_infolen;i++){
                *file>>_additional_info[i];
            }
            _additional_info[add_infolen-1] = '\0';
        }
        void save_to_file(ofstream *file){
            *file<<namelen<<" "<<_name<<" "<<m_phonelen<<" "<<_mobile_phone<<" "<<h_phonelen<<" "<<_home_phone<<" "<<faxlen<<" "<<_fax<<" "<<add_infolen<<" "<<_additional_info<<endl;
        }
    };

class Abonent *reallocate(class Abonent *pointer,int *size,int new_size){
    class Abonent *newpointer = new class Abonent [new_size];
    
    for(int i = 0;i<((*size)>new_size?(new_size):(*size));i++){
        newpointer[i] = Abonent(pointer[i]);
    }
    
    (*size) = new_size;
    delete[] pointer;
    return newpointer;
}
class Abonent *add(class Abonent *pointer,int *size){
    pointer = reallocate(pointer,size,(*size)+1);
    pointer[(*size)-1].edit_info('N');
    pointer[(*size)-1].edit_info('M');
    pointer[(*size)-1].edit_info('H');
    pointer[(*size)-1].edit_info('F');
    pointer[(*size)-1].edit_info('I');
    return pointer;
}
class Abonent *remove(class Abonent *pointer,int *size,int delete_pos){
    for(int i = delete_pos;i<(*size)-1;i++){
        pointer[i] = pointer[i];
    }
    pointer = reallocate(pointer,size,(*size)-1);
    return pointer;
}
class Abonent *read_database(class Abonent *pointer,int *size){
    ifstream file_in(filename);
    file_in>>(*size);
    pointer = new class Abonent[(*size)];
    for(int i = 0;i<(*size);i++){
        pointer[i].read_from_file(&file_in);
    }
    file_in.close();
    return pointer;
}
void save_database(class Abonent *pointer,int size){
    ofstream file_out(filename);
    file_out<<size<<endl;
    for(int i = 0;i<size;i++){
        pointer[i].save_to_file(&file_out);
    }
    file_out.close();
}
int main(){
    int size = 0;
    class Abonent *database;
    cout<<"enter filename: ";
    cin>>filename;
    database = read_database(database,&size);
    database = add(database,&size);
    database = add(database,&size);
    save_database(database,size);
    delete[] database;
}