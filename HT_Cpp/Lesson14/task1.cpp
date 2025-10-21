#include<iostream>
#include<string>


using namespace std;


struct book{
    
    private:
    string _name;
    string _autor;
    string _release_comp;
    string _style;

    public:
    void init(){

        cout<<"Enter book name, autor,release company, style"<<'\n';
        cin>>_name;
        cin>>_autor;
        cin>>_release_comp;
        cin>>_style;
    }
    void edit(char type){
        switch(type){
            case 'N':cout<<"Enter new name";cin>>_name;break;
            case 'A':cout<<"Enter new autor";cin>>_autor;break;
            case 'R':cout<<"Enter new release_comp";cin>>_release_comp;break;
            case 'S':cout<<"Enter new style";cin>>_style;break;
            default:cout<<"err";break;
        }
    }
    string getname(){
        return _name;
    }
    string getautor(){
        return _autor;
    }
    string get_releasecomp(){
        return _release_comp;
    }
    string getstyle(){
        return _style;
    }
};

int find_book(string name,char type,struct book *array,int size){
    for(int i = 0;i<size;i++){
        if(type == 'A'){
            if(array[i].getautor() == name){
                cout<<"book found at"<<i<<'\n';
                return 1;
            }
        }else{
            if(array[i].getname() == name){
                cout<<"book found at"<<i<<'\n';
                return 1;
            }
        }
    }
    return 0;
}

void sort(book* array, int size, char type) {
    bool flag = false;
    while (!flag) {
        flag = true;
        for (int i = 0; i < size - 1; i++) {
            bool shouldSwap = false;
            switch (type) {
                case 'A': shouldSwap = array[i].getautor() > array[i + 1].getautor(); break;
                case 'N': shouldSwap = array[i].getname() > array[i + 1].getname(); break;
                case 'R': shouldSwap = array[i].get_releasecomp() > array[i + 1].get_releasecomp(); break;
            }
            if (shouldSwap) {
                std::swap(array[i], array[i + 1]);
                flag = false;
            }
        }
    }
}

void printbooks(struct book *array,int size){
    for(int i = 0;i<size;i++){
        cout<<"Name: "<<array[i].getname()<<"\n";
        cout<<"autor: "<<array[i].getautor()<<"\n";
        cout<<"release comp: "<<array[i].get_releasecomp()<<"\n";
        cout<<"Style : "<<array[i].getstyle()<<"\n";
        cout<<'\n';
    }

}   

int main(){
    int size = 4;
    char _function;
    char arg;
    struct book *pointer;
    pointer = new book[size];
    for(int i = 0;i<size;i++){
        pointer[i].init();
    }
    cout<<"type 'B' to exit"<<'\n';
    while(_function != 'B'){
        cin>>_function;
        switch(_function){
            case 'S':{cout<<"enter sort type:";cin>>arg;sort(pointer,size,arg);}break;
            case 'F':{cout<<"enter search attr:";cin>>arg;cout<<"enter search name:";string buffer; cin>>buffer; find_book(buffer,arg,pointer,size);}break;
            case 'E':{cout<<"enter editing type:";cin>>arg;int pos;cout<<"enter editing pos:"; cin>>pos;pointer[pos].edit(arg);}break;
            case 'B':cout<<"exit...";
            case 'P':printbooks(pointer,size);break;
            default:cout<<"err \n";
        }
    }
    delete[] pointer;
}