#include<iostream>
#include<fstream>
#include<string>
#include<bitset>

using namespace std;

class File_basic{
    private:
        ifstream file_in;
        ofstream file_out;
    public:
        virtual void Show(const char *_filename){
            file_in.open(_filename);
            char buffer;
            while(file_in>>buffer){

                cout<<buffer;
            }
            file_in.close();
            cout<<endl;
        };
        
        virtual void Create(const char *_filename,const string &data){
            file_out.open(_filename);
            file_out<<data.size()<<endl;
            file_out<<data<<endl;
            file_out.close();
        }
        virtual void RANDOM(const char *_filename,int size){
            file_out.open(_filename);
            file_out<<size<<endl;
            for(int i = 0;i<size;i++){
                file_out<<random()<<" ";
            }   
            file_out<<endl;
            file_out.close();
        }
        virtual ~File_basic(){
            file_in.close();
            file_out.close();
        }
};
class File_binary:public File_basic{
    private:
        ifstream file_in;
        ofstream file_out;
        int size;
    public:
        void Show(const char *_filename)override{
            file_in.open(_filename,std::ios::binary);
            file_in>>size;
            int counter = 0;

            do{
                
                char buffer;
                file_in.read(reinterpret_cast<char*>(&buffer),1);
                if(file_in.eof()){
                    break;
                }
                bitset<8> bits(buffer);
                cout<<bits<<" ";
                counter++;
                if(counter%10 == 0){
                    cout<<endl;
                }
            }
            while(!file_in.eof());
            file_in.close();
            cout<<endl;
        }
        
        void Create(const char *_filename,const string &data)override{
            file_out.open(_filename,std::ios::binary);
            file_out.write(reinterpret_cast<char*>(data.size()),sizeof(data.size()));
            for(char i:data){
                file_out.write(reinterpret_cast<char*>(i),1);
                file_out.write(" ",1);
            }
            file_out.close();
        }   
        void RANDOM(const char *_filename,int size)override{
            file_out.open(_filename,std::ios::binary);
            file_out<<size<<endl;
            for(int i = 0;i<size;i++){
                long buffer = random();
                file_out.write(reinterpret_cast<char*>(&buffer),sizeof(long));
                file_out.write(" ",1);
            }   
            
            file_out.close();
        }
};
class File_ASCII:public File_basic{
    private:
        ifstream file_in;
        ofstream file_out;
    public:
        void Show(const char *_filename)override{
            file_in.open(_filename);
            char buffer;
            while(file_in>>buffer){
                cout<<(int)buffer<<" ";
            }
            file_in.close();
            cout<<endl;
        }
};
int main(){
    File_binary bin;
    // bin.RANDOM("BIN.bin",10);
    bin.Show("BIN.bin");
    File_basic basic;
    cout<<endl<<endl;
    basic.Create("TXT.txt","Hello! World");
    bin.Show("TXT.txt");
    File_ASCII ascii;
    ascii.Show("TXT.txt");
    ascii.Create("ASCII.txt","DWORD");
    ascii.Show("ASCII.txt");
}