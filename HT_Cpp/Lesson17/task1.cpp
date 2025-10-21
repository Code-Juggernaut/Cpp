#include<iostream>
#include<string.h>
#include<fstream>
#include<stdint.h>
using namespace std;

struct worker{
    int age;
    string profile;
    string name;
};
string Filename;


void read_database(struct worker **pointer,uint16_t *size){
    ifstream file_in(Filename);
    file_in>>(*size);
    *pointer = new struct worker[(*size)];
    for(int i = 0;i<(*size);i++){
        file_in>>(*pointer)[i].name>>(*pointer)[i].age>>(*pointer)[i].profile;
    }
    file_in.close();
}
void write_database(struct worker *pointer,uint16_t size){
    ofstream file_out(Filename);
    file_out<<size<<'\n';
    for(int i = 0;i<size;i++){
        file_out<<pointer[i].name<<" "<<pointer[i].age<<" "<<pointer[i].profile<<"\n";
    }
    file_out.close();
}

struct worker* add_data(struct worker *pointer,uint16_t *size){
    struct worker *newpointer = new struct worker[*size+1];
    for(int i = 0;i<(*size);i++){
        newpointer[i] = pointer[i];
    }
    delete[] pointer;
    (*size)++;

    cout<<"enter name: ";
    cin>>newpointer[(*size)-1].name;

    cout<<"enter age: ";
    cin>>newpointer[(*size)-1].age;

    cout<<"enter profile: ";
    cin>>newpointer[(*size)-1].profile;

    return newpointer;
}
struct worker* delete_data(struct worker *pointer, uint16_t *size, uint16_t pos){
    struct worker *newpointer = new struct worker[(*size)-1];
    (*size)--;
    for(int i = 0;i<(*size);i++){
        
        if(i<pos){
            newpointer[i] = pointer[i];
            
        }else{
            newpointer[i] = pointer[i+1];
        }
    }
    delete[] pointer;
    return newpointer;
}
void create_database(){
    ifstream file_exists(Filename);
    if(!file_exists){
        ofstream file_new(Filename);
        file_new<<0<<"\n";
        file_new.close();
        cout<<"database created! Please fill it \n ";
    }
    file_exists.close();
}

void find(struct worker *pointer,uint16_t size){
    string search_query;
    cout<<"enter search query(string(name only)):";
    cin>>search_query;
    for(int i =0;i<size;i++){
        if(search_query == pointer[i].name){
            cout<<"found worker : "<<pointer[i].profile<<" Age: "<<pointer[i].age<<"\n";
        }
    }
}
void print_database(struct worker *pointer,uint16_t size){
	for(int i = 0;i<size;i++){
        cout<<"Name :"<<pointer[i].name<<"\n";
		cout<<"Age :"<<pointer[i].age<<"\n";
		cout<<"Profile :"<<pointer[i].profile<<'\n';
        cout<<"\n--------------------------\n";
	}
}

void print_info(struct worker *pointer,uint16_t size){
    int from;
    int to;
    cout<<"Find worker at age(enter from and to)";
    cin>>from>>to;
    for(int i = 0;i<size;i++){
        if(pointer[i].age<=to && pointer[i].age>=from){
            cout<<"name: "<<pointer[i].name<<" profile: "<<pointer[i].profile<<'\n';
        }
    }
}
    
int main(){
    uint16_t size = 1;
    struct worker *pointer;
    cout<<"enter filename(with extention(.txt/.dat/.bin)):";
    cin>>Filename;
    create_database();
    read_database(&pointer,&size);
    char arg = ' ';

    while(arg != 'E'){
        cout<<"to exit enter 'E'";
        cout<<"enter command(S/D/P/F/A):";
        cin>>arg;
        switch(arg){
            case 'D':{cout<<"where I should delete?\n";int pos;cin>>pos;pointer = delete_data(pointer,&size,pos);}break;
            case 'P':cout<<"printing ...\n";print_database(pointer,size);break;
            case 'F':cout<<"finding ...\n";find(pointer,size);break;
            case 'A':{
                char arg = ' ';
                while(arg != 'E'){
                    pointer = add_data(pointer,&size);
                    cout<<"to exit enter 'E'";
                    cin>>arg;
                }
            }break;
            case 'S':cout<<"age finder \n";print_info(pointer,size);break;
            case 'E':cout<<"Exiting ...";break;
            default:cout<<"UNKNOWN\n";break;
        }
    }

    cout<<"Saving ...\n";
	write_database(pointer,size);
    cout<<"Saving Complete!";
    
	delete []pointer;
}
