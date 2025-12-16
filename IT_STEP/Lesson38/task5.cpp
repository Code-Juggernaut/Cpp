#include<set>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    set<string> a ={"Milk","Juice","Wine","Chocolate","Liquor"};
    set<string> b ={"Apple","Milk","Alcohol","Wine","Juice"};

    set<string>result;
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    for(auto i:result){
        cout<<i<<" ";
    }
    
}