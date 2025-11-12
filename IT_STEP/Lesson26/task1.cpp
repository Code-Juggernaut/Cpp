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
        void print() const{
            for(int i = 0;i<5;i++){
                cout<<"Value at"<<i<<" = "<<data[i]<<endl;
            }
            cout<<endl;
        }
};

class is_even{
    public:
    bool operator()(int x) const{
        return x%2 == 0;
    }
};

int main(){
    is_even test;
    int buff1[5] = {1,2,3,4,5};
    int buff2[5] = {1,2,3,4,5};
    int s = buff1[1];
    Array object1(buff1);
    Array object2;

    


    object1.print();
    object2.print();
    cout<<((object1 == object2)?("True"):("False"))<<endl;
    cout<<((object1 != object2)?("True"):("False"))<<endl;

    cout<<"a == b "<<(object1 == object2?("True"):("False"))<<endl;
    cout<<"a == b "<<(buff1 == buff2?("True"):("False"))<<endl;
    cout<<"a != b "<<(object1 != object2?("True"):("False"))<<endl;
    cout<<"a != b "<<(buff1 != buff2?("True"):("False"))<<endl;\
    cout<<"a <= b "<<(object1 <= object2?("True"):("False"))<<endl;
    cout<<"a <= b "<<(buff1 <= buff2?("True"):("False"))<<endl;
    cout<<"a >= b "<<(object1 >= object2?("True"):("False"))<<endl;
    cout<<"a >= b "<<(buff1 >= buff2?("True"):("False"))<<endl;
    cout<<"a < b "<<(object1 < object2?("True"):("False"))<<endl;
    cout<<"a < b "<<(buff1 < buff2?("True"):("False"))<<endl;
    cout<<"a > b "<<(object1 > object2?("True"):("False"))<<endl;
    cout<<"a > b "<<(buff1 > buff2?("True"):("False"))<<endl;
    object1[3] = 100;
    cout<<object1[3]<<endl;

    cout<<"is even: ";
    for(int i = 0;i<5;i++){
        if(test(object1[i])){
            cout<<buff1[i]<<" ";
        }
    }
    cout<<endl;
}
