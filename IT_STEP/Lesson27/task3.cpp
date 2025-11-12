#include<iostream>
#include<stdio.h>

using namespace std;

template <typename t>

class Sensortek{
    private:
        t *data;
        int size;
    public:
        Sensortek(){
            data = new t[1];
            size = 1;
        }
        ~Sensortek(){
            delete[] data;
        }
        void add(const t &value){
            t *new_data = new t[size+1];
            for(int i = 0;i<size;i++){
                new_data[i] = data[i];
            }
            new_data[size] = value;
            delete[]data;
            data = new_data;
            size++;
        }
        int get_reading_amount(){
            return size;
        }
        template <typename uni>
    
        uni avr(){
            t sum = 0;
            for(int i = 0;i<size;i++){
                sum+= data[i];
            }
            sum/=size;
            return static_cast<uni>(sum);
        }
        t max(){
            t max = data[0];
            for(int i = 0;i<size;i++){
                if(max<data[i]){
                    max = data[i];
                }
            }
            return max;
        }
        t min(){
            t min = data[0];
            for(int i = 0;i<size;i++){
                if(min>data[i]){
                    min = data[i];
                }
            }
            return min;
        }
        void print_data(){
            for(int i = 0;i<size;i++){
                cout<<"measure No"<<i+1<<" "<<data[i]<<endl;
            }
        }
};


int main(){
    class Sensortek<float> BME280;

    for(int i = 0;i<10;i++){
        BME280.add((rand()%100)/0.24);
    }
    cout<<"Object  avr:"<<BME280.avr<double>()<<endl;
    cout<<"Object  max:"<<BME280.max()<<endl;
    cout<<"Object  min:"<<BME280.min()<<endl;
    cout<<"Object  reading amount:"<<BME280.get_reading_amount()<<endl;
    cout<<"=====================BME280 TOTAL DATA======================="<<endl;
    BME280.print_data();
}