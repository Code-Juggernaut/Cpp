#include<iostream>
#include<vector>
#include<iterator>
#include<deque>
#include<algorithm>

using namespace std;

int main(){
    const int init[] = {1,2,3,4,5};
    vector<int> v1(5);
    copy(init,init+5,v1.begin());
    copy(v1.begin(),v1.end(),ostream_iterator<int>(cout," "));
    copy(v1.rbegin(),v1.rend(),ostream_iterator<int>(cout," "));
    
    cout<<endl;
    
    const char *arr1[] = {"Hello", "World!","I"};
    const char *arr2[] = {"I am","Code_Juggernaught","See you"};
    deque<const char *>names(arr1,arr1+3);
    // insert_iterator<deque<const char *>>it(names,names.begin()+2);
    // copy(arr2,arr2+3,it);

    deque<const char *>::iterator i = names.begin()+2;
    copy(arr2,arr2+3,inserter(names,i));    

    deque<const char *>::iterator j;
    for(j = names.begin();j!=names.end();j++){
        cout<<*j<<" ";
    }
    cout<<endl;
    deque<int>S;
    copy(istream_iterator<int,char>(cin),istream_iterator<int,char>(),back_inserter(S));
    copy(S.begin(),S.end(),ostream_iterator<int,char>(cout,"  "));
}