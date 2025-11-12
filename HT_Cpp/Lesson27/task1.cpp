#include<iostream>
#include<stdio.h>

using namespace std;

template <typename t>
class Matrix{
    private:
        t **data;
        int _sizex;
        int _sizey;
    public:
        // ================= CONSTRUCTOR =======================
        Matrix(){
            data = new t*[1];
            data[0] = new t[1];
            _sizex = 1;
            _sizey = 1;
        }
        Matrix(int sizex,int sizey):_sizex(sizex),_sizey(sizey){
            data = new t*[sizey];
            for(int i = 0;i<_sizey;i++){
                data[i] = new t[_sizex];
            }
        }

        ~Matrix(){
            for(int i = 0;i<_sizey;i++){
                delete[] data[i];
            }
            delete[] data;
        }
        Matrix(class Matrix &other){
            _sizex = other._sizex;
            _sizey = other._sizey;
            data = new t*[_sizey];
            for(int i = 0;i<_sizey;i++){
                data[i] = new t[_sizex];
            }
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    data[i][j] = other.data[i][j];
                }
            }
        }
        
        //=============== OVERLOADS =============
        class Matrix &operator=(class Matrix other){
            if(this == &other){
                return *this;
            }
            for(int i = 0;i<_sizey;i++){
                delete[] data[i];
            }
            _sizex = other._sizex;
            _sizey = other._sizey;
            
            delete[] data;
            data = new t*[_sizey];

            for(int i = 0;i<_sizey;i++){
                data[i] = new t[_sizex];
            }
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    data[i][j]= other.data[i][j];
                }
            }
            return *this;
        }
        class Matrix operator+(const t value) const{
            class Matrix _new(_sizex,_sizey);
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    _new.data[i][j] = data[i][j] + value;
                }
            }
            return _new;
        }
        class Matrix operator-(const t value) const{
            class Matrix _new(_sizex,_sizey);
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    _new.data[i][j] = this->data[i][j] - value;
                }
            }
            return _new;
        }
        class Matrix operator*(const t value) const{
            class Matrix _new(_sizex,_sizey);
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    _new.data[i][j] = this->data[i][j] * value;
                }
            }
            return _new;
        }
        class Matrix operator/( t value) const{
            class Matrix _new(_sizex,_sizey);
            value = (value == 0?(1):(value));
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    _new.data[i][j] = this->data[i][j] / value;
                }
            }
            return _new;
        }
        t operator!() const{
            t max = data[0][0];
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    max = (max<data[i][j]?(data[i][j]):(max));
                }
            }
            return max;
        }
        t operator~() const{
            t min = data[0][0];
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    min = (min>data[i][j]?(data[i][j]):(min));
                }
            }
            return min;
        }
        t operator|(int seed){
            srand(seed);
            for(int i = 0;i<_sizey;i++){
                for(int j = 0;j<_sizex;j++){
                    data[i][j] = rand()%10;
                }
            }
            return 0;
        }
        void print() const{
            for(int i = 0;i<_sizey;i++){
                for(int j =0;j<_sizex;j++){
                    cout<<data[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    };

int main(){
    class Matrix<int>obj1(3,3);
    class Matrix<int>obj2;
    class Matrix<int>result;
    obj1|10;
    obj1.print();
    obj2.print();
    obj2 = obj1;
    result = obj1+10;
    obj1.print();
    result.print();
    result = obj2-10;
    obj2.print();
    result.print();
    

    int max = !obj1;
    int min = ~obj1;
    cout<<"max "<<max<<" min"<<min<<endl;
    result = obj2*10;
    obj2.print();
    result.print();
    result = result/20;
    obj2.print();
    result.print();
}