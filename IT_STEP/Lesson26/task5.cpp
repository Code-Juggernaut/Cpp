#include<iostream>
#include<string.h>
using namespace std;

class Box{
    private:
        int sizex;
        int sizey;
        int sizez;
        char _type;
        int price;
    public:
        Box(int x, int y, int z, char type):sizex(x),sizey(y),sizez(z),_type(type){
            price = 2;
        }
        float get_volume(){
            return sizez*sizex*sizey;
        }
        friend class Inspector;

};
class Inspector{
    private:
        int price_mult;
    public:
        Inspector(){
            price_mult = 2;
        }
        void check(class Box &parsel){
            cout<<"dimentions: "<<" X: "<<parsel.sizex<<" Y: "<<parsel.sizey<<" Z: "<<parsel.sizez<<endl;
            cout<<"type :"<<parsel._type<<endl;
            if( parsel._type == 'C'&& parsel.get_volume()>10E6){
                parsel.price++;
                parsel.price*=price_mult;
            }else if(parsel._type == 'B'&& parsel.get_volume()<10E6){
                price_mult*=5;
                parsel.price++;
                parsel.price*=price_mult;
            }else if(parsel._type == 'M'&& parsel.get_volume()<10E6){
                price_mult*=100;
                parsel.price++;
                parsel.price*=price_mult;
            }else{
                cout<<"no extra charge :)"<<endl;
                //price_mult*=0;
            }
            cout<<"extra charge :"<<price_mult<<endl;
            cout<<"total price: "<<parsel.price*price_mult<<endl;
            price_mult = 2;
        }
};

int main(){
    Box obj1(10,10,10,'C');
    Box obj2(10,10,10,'B');
    Box obj3(10,10,10,'M');
    Box obj4(10000,10000,10000,'C');
    Inspector nova_poshta;
    
    nova_poshta.check(obj1);
    nova_poshta.check(obj2);
    nova_poshta.check(obj3);
    nova_poshta.check(obj4);

}