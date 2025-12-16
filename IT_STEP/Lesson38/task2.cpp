#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
#include<iterator>
#include<ctime>

using namespace std;

int main(){
    vector<int>v1;
    ostream_iterator<int> ptr(cout," ");
    for(int i = 0;i<10;i++){
        v1.push_back(random()%100);
    }
    copy(v1.begin(),v1.end(),ptr);
    cout<<endl;

    int _min = *min_element(v1.begin(),v1.end());
    int _max = *max_element(v1.begin(),v1.end());

    cout<<"Min: "<<_min<<" "<<"max"<<_max<<endl;
    sort(v1.begin(),v1.end(),greater<int>());
    copy(v1.begin(),v1.end(),ptr);
    cout<<"sort"<<endl;
    sort(v1.begin(),v1.end());
    copy(v1.begin(),v1.end(),ptr);
    cout<<"sort"<<endl;
    vector<int>buffer(v1.size());
    transform(v1.begin(),v1.end(),buffer.begin(),[](int x){return x+5;});
    copy(buffer.begin(),buffer.end(),ptr);
    cout<<"+5"<<endl;
    transform(v1.begin(),v1.end(),buffer.begin(),[](int x){return x-10;});
    copy(buffer.begin(),buffer.end(),ptr);
    cout<<"-10"<<endl;

    auto temp = remove_if(v1.begin(),v1.end(),[](int val){return val%5 == 0;});
    v1.erase(temp,v1.end());
    copy(v1.begin(),v1.end(),ptr);
    cout<<"erased"<<endl;
}