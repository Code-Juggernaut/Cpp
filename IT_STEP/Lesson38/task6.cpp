#include<set>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    set<string> a ={"John","Alice","Bob","Mary","Amiya"};
    set<string> b ={"Mountain","John","Alice","Hung","Sankta"};

    set<string>result;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    for(auto i:result){
        cout<<i<<" ";
    }
}   