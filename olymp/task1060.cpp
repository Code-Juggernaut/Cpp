#include<iostream>
#include<queue>

using namespace std;

struct pos{
    int x;
    int y;
};

int sx,sy,ex,ey;

int main(){
    int size = 0;
    cin>>size;
    char array[size][size];
    char copy[size][size];
    char buff;
    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            cin>>array[i][j];
            copy[i][j] = /*array[i][j]*/' ';
            if(array[i][j] == 'X'){
                ex = j;
                ey = i;
            }
            if(array[i][j] == '@'){
                sx = j;
                sy = i;
            }
        }
    }


    queue<pos> route;

    pos buffer;
    buffer.x = ex;
    buffer.y = ey;

    route.push(buffer);
    int x = ex,y = ey;

    bool is_found = 0;
    while(!route.empty()&& is_found == 0){
        struct pos Point;
        Point = route.front();
        route.pop();
        x = Point.x;
        y = Point.y;
        if((x+1)<size && y<size && array[Point.y][Point.x+1] == '.' && copy[Point.y][Point.x+1] == ' '){
            copy[Point.y][Point.x+1] = 'R';
            buffer.x = Point.x+1;
            buffer.y = Point.y;
            route.push(buffer);
        } if((x-1)>=0 && y<size && array[Point.y][Point.x-1] == '.' && copy[Point.y][Point.x-1] == ' '){
            copy[Point.y][Point.x-1] = 'L';
            buffer.x = Point.x-1;
            buffer.y = Point.y;
            route.push(buffer);
        } if(x<size && (y+1)<size &&array[Point.y+1][Point.x] == '.' && copy[Point.y+1][Point.x] == ' '){
            copy[Point.y+1][Point.x] = 'D';
            buffer.x = Point.x;
            buffer.y = Point.y+1;
            route.push(buffer);
        }if(x<size && (y-1)>=0 && array[Point.y-1][Point.x] == '.' && copy[Point.y-1][Point.x] == ' '){
            copy[Point.y-1][Point.x] = 'U';
            buffer.x = Point.x;
            buffer.y = Point.y-1;
            route.push(buffer);
        }
        if(buffer.x == sx && buffer.y == sy){
            is_found = 1;
            break;
        }
    }
    if(is_found ==1){
        cout<<"Found!";
    }else{
        cout<<"Not found";
    }
}