#include<iostream>

using namespace std;
struct links{
    int from;
    int to;
    int length;
};
int main(){
    int n,m;
    cin>>n>>m;
    int sum =1;
    int output_len = 0;
    int number_min = 0;
    int min_length = 0;


    links array[m+1];
    int colors[n+1];

    for(int i = 1;i<=m;i++){
        cin>>array[i].from>>array[i].to>>array[i].length;
        sum+=array[i].length;
    }
    for(int i =1 ;i<=n;i++){
        colors[i] = i;
    }

    for(int i = 1;i<n;i++){
        int min_length = sum;
        for(int j = 1;j<=m;j++){
            if(colors[array[j].from] != colors[array[j].to] && array[j].length<min_length){
                number_min = j;
                min_length = array[j].length;
            }
        }
        output_len += min_length;
        int end_color = colors[array[number_min].to];
        for(int i =1;i<=n;i++){
            if(end_color == colors[i]){
                colors[i] = colors[array[number_min].from];
            }
        }
    }
    cout<<output_len;
}