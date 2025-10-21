#include<iostream>
#include<cstring>
const int sizex = 100;
const int sizey = 30;

class graphics{
    public:
        graphics(){

        };
        void create_canvas(){
            for(int i = 0;i<sizey;i++){
                for(int j = 0;j<sizex;j++){
                    draw_buffer[i][j] = ' ';
                }
            }
        }
        void fill_canvas(char symbol){
            for(int i = 0;i<sizey;i++){
                for(int j = 0;j<sizex;j++){
                    draw_buffer[i][j] = symbol;
                }
            }
        }
        void draw_array(char array[20][30],int offset_x,int offset_y){
            for(int i = 0;i<19;i++){
                for(int j = 0;j<30;j++){
                    draw_buffer[i+offset_y][j+offset_x] = array[i][j];
                }
            }
        }
        void draw_mirrored_array(char array[20][30],int offset_x,int offset_y){
            for(int i = 0;i<19;i++){
                for(int j = 29;j>=0;j--){
                    draw_buffer[i+offset_y][29-j+offset_x] = array[i][j];
                }
            }
        }
        void draw_text(std::string text,int offset_x,int offset_y){
            for(int i = 0;i<text.size();i++){
                draw_buffer[offset_y][offset_x+i] = text[i]; 
            }
        }
        void print(){
            for(int i = 0;i<sizey;i++){
                for(int j = 0;j<sizex;j++){
                    std::cout<<draw_buffer[i][j];
                }
                std::cout<<'\n';
            }
        }
        void change_color(std::string color){
            std::cout<<color;
        }
    private:
    
    char draw_buffer[sizey][sizex];

};