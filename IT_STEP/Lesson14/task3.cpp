#include<math.h>
#include<iostream>

using namespace std;

struct data{
    private:
        int x;
        int y;

    public:
        void setpoints(){
            cout<<"enter coords: x y";
            cin>>x>>y;
        }
        float calc_len(struct data pointer){
            return sqrt(((pointer.y-y)*(pointer.y-y))+((pointer.x-x)*(pointer.x-x)));
        }
} len;

int main(){
    len.setpoints();
    struct data point2;
    point2.setpoints();
    cout<<len.calc_len(point2);
}