#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main(){
    const int init[] = {1,2,3,4,5};
    vector<int> v1(5);
    copy(init,init+5,v1.begin());
    copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," "));
    copy(v1.rbegin(),v1.rend(),ostream_iterator<int>(cout," "));
}