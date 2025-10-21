#include<iostream>
struct params{
    private:
        int x;
        int y;
        int posx;
        int posy;
    public:
        void init(int _x,int _y){
            x = _x;
            y = _y;
        }
        void resize(float scale){
            x*=scale;
            y*=scale;
        }
        void relocate(int tox,int toy){
            posx = tox;
            posy = toy;
        }
        void print_rect(){
            
            for(int i = 0;i<y;i++){
                for(int j = 0;j<posx;j++){
                    std::cout<<" ";
                }
                for(int j = 0;j<x;j++){

                        
                    
                    std::cout<<(char)0xB0;
                }
                std::cout<<"\n";
            }
            std::cout<<"\n";
        }
    
}rect;
int main(){
    rect.init(12,12);
    rect.relocate(10,10);
    rect.print_rect();
    rect.resize(0.5);
    rect.print_rect();
}