#include<iostream>
#include<string.h>

using namespace std;

class String{
    private:
        char *string_line;
        int _size;
        friend class Binary_String;
    public:
    //--------------------------CONSTRUCTORS------------------------------
    String(const char *array){
        _size = strlen(array)+1;
        string_line = new char[_size];
        strcpy(string_line,array);
    }
    String(){
        string_line = nullptr;
        _size = 0;
    }
//--------------------------RULE OF FIVE-----------------------
    String(const class String &Other){
        this->_size = Other._size;
        this->string_line = new char[_size];
        strcpy(this->string_line,Other.string_line);
    }
    String &operator=(const class String &Other){
        if(this == &Other){
            return *this;
        }
        delete[] this->string_line;
        this->_size = Other._size;
        this->string_line = new char[_size];

        strcpy(this->string_line,Other.string_line);
        return *this;
    }

    String(String &&Other)noexcept{
        this->string_line = Other.string_line;
        this->_size = Other._size;
        Other.string_line = nullptr;
        Other._size = 0;
    }
    String &operator=(class String &&Other)noexcept{
        if(this == &Other){
            return *this;
        }
        delete[] this->string_line;
        this->string_line = Other.string_line;
        this->_size = Other._size;
        Other.string_line = nullptr;
        Other._size = 0;
        return *this;
    }
    ~String(){
        if(string_line!=nullptr){
            delete[] string_line;
        }
        
    }
    //-------------------------------OVERLOADS--------------------------

    String& operator+=(const String &Other){
        char *new_str = new char[this->_size+Other._size-1];
        strcpy(new_str,this->string_line);
        strcat(new_str,Other.string_line);
        delete[]this->string_line;
        this->string_line = new_str;
        this->_size = this->_size+Other._size-1;
        return *this;
    }
    String operator+(const String &Other){
        int size = this->_size+Other._size-1;
        char *buffer = new char[size];
        strcpy(buffer,this->string_line);
        strcat(buffer,Other.string_line);
        class String new_class(buffer);
        delete[] buffer;
        return new_class;
    }
    bool operator==(const String &Other)const{
        return strcmp(this->string_line,Other.string_line) == 0;
    }
    bool operator!=(const String &Other)const{
        return !(*this==Other);
    }
    //----------------------------FUNCTIONS---------------
    char *get_line(){
        return this->string_line;
    }
    void remove_string(){
        delete[] this->string_line;
        this->_size = 0;
        this->string_line = nullptr;
    }
    char* get_line(int &size){
        size = this->_size;
        return this->string_line;
    }
};

class Binary_String: public String{
    private:

    public:

    Binary_String(const char *array):String(array){
        for(int i = 0;i<strlen(array);i++){
            if(array[i]!= '0' && array[i]!= '1'){
                remove_string();
                cout<<"Corrupted!";
                break;
            }
        }
    }
    Binary_String():String(){
        
    }
    //-------------- CHATGPT PART start------------------
    Binary_String operator+(const Binary_String& other) const {
        const char* a = this->string_line;
        const char* b = other.string_line;

        int lenA = strlen(a), lenB = strlen(b);
        int maxLen = max(lenA, lenB);
        string result(maxLen, '0');

        int carry = 0;
        for (int i = 0; i < maxLen; i++) {
            int bitA = (i < lenA) ? a[lenA - 1 - i] - '0' : 0;
            int bitB = (i < lenB) ? b[lenB - 1 - i] - '0' : 0;
            int sum = bitA + bitB + carry;
            result[maxLen - 1 - i] = (sum % 2) + '0';
            carry = sum / 2;
        }

        if (carry) result.insert(result.begin(), '1');

        return Binary_String(result.c_str());
    }

    Binary_String& operator+=(const Binary_String& other) {
        *this = *this + other;
        return *this;
    }
    //-------------- CHATGPT PART END------------------

    void Change_sign(){
        string_line[0] = (string_line[0] == '1'?('0'):('1'));
    }
    String operator!(){
        for(int i = 0;i<this->_size;i++){
            this->string_line[i] = (this->string_line[i] == '1'?('0'):('1'));
        }
        return *this;
    }
};

int main(){
    String obj1("Hello world!");
    String obj2 = obj1; 
    String obj3;
    cout<<(obj1 == obj2)<<" "<<(obj1!=obj2);
    obj3 = obj1+obj2;
    cout<<obj3.get_line();

    Binary_String bin1("01000101011");
    Binary_String bin2 = bin1;
    bin1+=bin2;
    cout<<bin1.get_line()<<endl;
    bin1.Change_sign();
    cout<<bin1.get_line()<<endl;
    !bin1;
    cout<<bin1.get_line()<<endl;
}