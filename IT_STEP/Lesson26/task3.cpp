#include<iostream>

using namespace std;

class Array{
    private:
        int data[5];
    public:
        Array(const int *arr){
            for(int i = 0;i<5;i++){
                data[i] = arr[i];
            }
        }   
        Array(){
            for(int i = 0;i<5;i++){
                data[i] = 0;
            }
        }
        bool operator==(class Array other){
            for(int i = 0;i<5;i++){
                if(this->data[i]!=other.data[i]){
                    return 0;
                }
            }
            return 1;
        }
        bool operator!=(class Array other){
            /*for(int i = 0;i<5;i++){
                if(this->data[i]==other.data[i]){
                    return 0;
                }
            }
            return 1;*/
            return !(*this == other);
        }

        bool operator<(class Array other){
            for(int i = 0;i<5;i++){
                if(this->data[i]>=other.data[i]){
                    return 0;
                }
            }
            return 1;
        }
        bool operator>(class Array other){
            return !(*this < other);
        }
        bool operator<=(class Array other){
            for(int i = 0;i<5;i++){
                if(this->data[i]>other.data[i]){
                    return 0;
                }
            }
            return 1;
        }
        bool operator>=(class Array other){
            return !(*this <= other); 
        }

        int &operator[](int index){
            if(index>0&& index<sizeof(this->data)){
                return data[index];
            }
                cout<<"out of range";
                static int dummy = -1;
            return dummy;
        }
        // void print() const{
        //     for(int i = 0;i<5;i++){
        //         cout<<"Value at"<<i<<" = "<<data[i]<<endl;
        //     }
        //     cout<<endl;
        // }
        friend ostream& operator<<(ostream &output,class Array & array);
        friend istream& operator>>(istream &input,class Array & array);
};
ostream& operator<<(ostream &output,class Array & array){
    output<<"array = ";
    for(int i = 0;i<5;i++){
        output<<array.data[i]<<" ";
    }
    return output;
}
istream& operator>>(istream &input,class Array & array){
    for(int i = 0;i<5;i++){
        cout<<"enter element "<<i<<" :";
        input>>array.data[i];
    }
    return input;
}

int main(){
    Array obj1;
    cin>>obj1;
    cout<<obj1;
}