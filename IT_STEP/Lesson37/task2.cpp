#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<deque>


using namespace std;

int main(){
    vector<char> v1;
    copy(istream_iterator<char,char>(cin),istream_iterator<char,char>(),back_inserter(v1));
    copy(v1.rbegin(),v1.rend(),ostream_iterator<char>(cout,""));
    

    deque<char> dq1(v1.begin(),v1.begin()+5);
    copy(istream_iterator<char,char>(cin),istream_iterator<char,char>(),front_inserter(dq1));
    copy(dq1.begin(),dq1.end(),ostream_iterator<char>(cout,""));

    vector<char>::iterator ptr = v1.begin();
    ptr+=2;
    char buffer;
    for(int i = 0;i<3;i++){
        cin>>buffer;
        inserter(v1,ptr) = buffer;
        ptr++;
    }
    copy(v1.begin(),v1.end(),ostream_iterator<char>(cout,""));
}