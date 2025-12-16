#include<map>
#include<string>
#include<sstream>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){
    string text = "Hello Hello It's me me Welcome to the home";

    map<string,int> word_count;
    istringstream stream(text);
    string word;
    while(stream>>word){
        ++word_count[word];
    }
    for_each(word_count.begin(),word_count.end(),[](const auto &words){cout<<words.first<<" "<<words.second<<endl;});
    
}