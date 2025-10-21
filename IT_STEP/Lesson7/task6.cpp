#include<iostream>
#include<cstring>
using namespace std;
void draw_pyramid(int level, int current = 1){
    if(current > level){
        return;
    }
    int space = level-current;
    int stars = 2*current-1;
    cout<<string(space,' ')<<string(stars,'*')<<'\n';
    return draw_pyramid(level,current+1);
}
int main(){
    draw_pyramid(10);
}