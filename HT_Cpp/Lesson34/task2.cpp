/**
 * CAUTION: USING random()
 * If not working replace random() with rand()
 */

#include<iostream>

using namespace std;

class Invalid_Matrix_Size:public exception{
    private:
        string message;
    public:
        Invalid_Matrix_Size(int size_x, int size_y, int size_m, int size_z){
            message = "Matrix "+to_string(size_x)+"x"+to_string(size_y)+" != "+to_string(size_m)+"x"+to_string(size_z)+'\n';
        }
        const char *what(){
            return message.c_str();
        }
};

class Matrix{
    private:
        int _sizex;
        int _sizey;
        int **matrix;

    public:
        Matrix(int sizex,int sizey):_sizex(sizex),_sizey(sizey){
            matrix = new int*[sizex];
            for(int i = 0;i<sizex;i++){
                matrix[i] = new int[sizey];
            }
        }
        Matrix():_sizex(0),_sizey(0){
            matrix = nullptr;
        }
        ~Matrix(){
            for(int i = 0;i<_sizex;i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        Matrix(const Matrix &other){
            this->_sizex = other._sizex;
            this->_sizey = other._sizey;

            this->matrix = new int*[_sizex];
            for(int i = 0;i<_sizex;i++){
                this->matrix[i] = new int[_sizey];
            }

            for(int i = 0;i<_sizex;i++){
                for(int j = 0;j<_sizey;j++){
                    this->matrix[i][j] = other.matrix[i][j];
                }
            }
        }

        Matrix &operator=(const Matrix &other){
            if(this == &other){
                return *this;
            }

            for(int i = 0;i<this->_sizex;i++){
                delete[] this->matrix[i];
            }
            delete[] this->matrix;

            this->_sizex = other._sizex;
            this->_sizey = other._sizey;

            this->matrix = new int*[this->_sizex];
            for(int i = 0;i<_sizex;i++){
                matrix[i] = new int[this->_sizey];
            }
            for(int i = 0;i<_sizex;i++){
                for(int j = 0 ;j<_sizey;j++){
                    this->matrix[i][j] = other.matrix[i][j];
                }
            }
            return *this;
        }



        Matrix operator+(Matrix const &other){
            try{
                if(this->_sizex != other._sizex || this->_sizey!= other._sizey){
                    throw(Invalid_Matrix_Size(this->_sizex,this->_sizey,other._sizex,other._sizey));
                }else{
                    Matrix new_matrix(_sizex,_sizey);
                    for(int i = 0;i<_sizex;i++){
                        for(int j  =0;j<_sizey;j++){
                            new_matrix.matrix[i][j] = this->matrix[i][j]+other.matrix[i][j];
                        }
                    }
                    return new_matrix;
                }
            }
            catch(Invalid_Matrix_Size &error){
                cout<<error.what();
            }
            return Matrix(0,0);
        }


        void Generate_random(){
            for(int i = 0;i<_sizex;i++){
                for(int j = 0;j<_sizey;j++){
                    matrix[i][j] = random()%20;
                }
            }
        }

        void print(){
            for(int i = 0;i<_sizex;i++){
                for(int j = 0;j<_sizey;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
};

int main(){
    Matrix m1(3,3);
    Matrix m2(3,3);
    Matrix m3(5,5);
    Matrix buffer;

    m1.Generate_random();
    m2.Generate_random();
    m3.Generate_random();
    m1.print();
    m2.print();
    m3.print();

    buffer = m1+m2;
    buffer.print();

    buffer = m1+m3;
}