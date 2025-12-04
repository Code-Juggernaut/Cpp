#include<iostream>
#include<string.h>

using namespace std;

class Slide{
    string info;
    public:
    Slide(const string &data):info(data){}
    Slide(){

    }
    void show(){
        cout<<"Info:"<<info;
    }
};
class Presentation{
    private:
        static const int size=5;
        Slide *slides[size];
        int slides_amount;
        public:
        Presentation():slides_amount(0){
        }

        void add(Slide slide){
            if(slides_amount<size){
                slides[slides_amount++] = &slide;
            }else{
                cout<<"empty";
            }
        }
        void show(){
            cout<<"list::\n";
            for(int i = 0;i<slides_amount;i++){
                slides[i]->show();
                cout<<endl;
            }
        }
};


int main(){
    Slide sl1("Hello");
    Slide sl2("About us");
    Slide sl3("New");

    Presentation present;
    present.add(sl1);
    present.add(sl2);
    present.add(sl3);
    present.show();
}