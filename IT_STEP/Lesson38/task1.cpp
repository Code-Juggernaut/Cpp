#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
#include<iterator>
#include<ctime>

using namespace std;

class Fibonacci{
    private:
    int val1;
    int val2;

    public:
    Fibonacci():val1(0),val2(1){

    }
    int operator()(){
        int prev_sum = val1+val2;
        val1 = val2;
        val2 = prev_sum;
        return val1;
    }

};

int main(){
    srand(time(NULL));
    Fibonacci gen;
    vector<int> v1(10);
    vector<int> v2(10);
    vector<int> v3(100);
    fill(v2.begin(),v2.end(),5);
    generate(v1.begin(),v1.end(),gen);

    ostream_iterator<int> ptr(cout," ");
    copy(v1.begin(),v1.end(),ptr);
    cout<<endl;
    copy(v2.begin(),v2.end(),ptr);
    cout<<endl;
    generate(v3.begin(),v3.end(),[](){return rand()%100;});
    copy(v3.begin(),v3.end(),ptr);

    greater<int>gr;
    sort(v3.begin(),v3.end(),gr);
    cout<<endl;
    copy(v3.begin(),v3.end(),ptr);

    sort(v3.begin(),v3.end());
    if(binary_search(v3.begin(),v3.end(),5)){
        cout<<"found";
    }else{
        cout<<"Not found";
    }

    cout<<endl;
    long int sum = accumulate(v3.begin(),v3.end(),0);

    cout<<"Sum = "<<sum<<endl;

    int init  = 1000;
    cout<<accumulate(v3.begin(),v3.end(),0,minus<int>());
    
    int max_ = *max(v1.begin(),v1.end());
    vector<int> buffer(10);
    vector<int> buffer2(3);
    vector<int>temp1 = {1,2,3};
    vector<int>temp2 = {4,5,6};
    transform(temp1.begin(),temp1.end(),temp2.begin(),buffer2.begin(),[](int x,int y){return x+y;});
    copy(buffer2.begin(),buffer2.end(),ptr);
    transform(v1.begin(),v1.end(),v1.begin(),buffer.begin(),[](int x,int y){return x+y;});
    copy(buffer.begin(),buffer.end(),ptr);

}