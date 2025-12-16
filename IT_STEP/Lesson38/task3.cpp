#include<set>
#include<sstream>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
    string text = "Hello Hello It's me me Welcome to the home";
    set<string> unique_words;
    istringstream stream(text);
    string word;
    while(stream>>word){
        unique_words.insert(word);
    }
    for_each(unique_words.begin(),unique_words.end(),[](const string &words){cout<<words<<" ";});

    set<int> a ={1,2,3,4,5};
    set<int> b ={3,4,5,6,7};

    set<int>result ;
    set<int>result2;
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(result,result.begin()));
    set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(result2,result2.begin()));
    for(int i :result){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i :result2){
        cout<<i<<" ";
    }
}