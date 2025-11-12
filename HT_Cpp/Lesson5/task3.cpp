#include "header_file.h"

void print(int array[sizex][sizey]) {
    for (int i = 0; i < sizex; ++i){
        for (int j = 0; j < sizey; ++j)
            cout << array[i][j] << " ";
        cout <<'\n';
    }
}

void shiftl(int array[sizex][sizey], int steps) {
    steps %= sizey;
    for (int i = 0; i < sizex; ++i) {
        for (int s = 0; s < steps; ++s) {
            int temp = array[i][0];
            for (int j = 0; j < sizey - 1; ++j)
                array[i][j] = array[i][j + 1];
            array[i][sizey - 1] = temp;
        }
    }
}

void shiftr(int array[sizex][sizey], int steps) {
    steps %= sizey;
    for (int i = 0; i < sizex; ++i) {
        for (int s = 0; s < steps; ++s) {
            int temp = array[i][sizey - 1];
            for (int j = sizey - 1; j > 0; --j)
                array[i][j] = array[i][j - 1];
            array[i][0] = temp;
        }
    }
}

void shiftu(int array[sizex][sizey], int steps) {
    steps %= sizex;
    for (int j = 0; j < sizey; ++j) {
        for (int s = 0; s < steps; ++s) {
            int temp = array[0][j];
            for (int i = 0; i < sizex - 1; ++i)
                array[i][j] = array[i + 1][j];
            array[sizex - 1][j] = temp;
        }
    }
}

void shiftd(int array[sizex][sizey], int steps) {
    steps %= sizex;
    for (int j = 0; j < sizey; ++j) {
        for (int s = 0; s < steps; ++s) {
            int temp = array[sizex - 1][j];
            for (int i = sizex - 1; i > 0; --i)
                array[i][j] = array[i - 1][j];
            array[0][j] = temp;
        }
    }
}

int main() {
    int array[sizex][sizey];
    for (int i = 0; i < sizex; ++i)
        for (int j = 0; j < sizey; ++j)
            array[i][j] = rand() % 1000;

    cout<<defcolor<< "start arrayay:\n";
    print(array);

    char direction;
    int shiftCount;
    cout << "\nEnter swap dir(l,r,u,d): ";
    cin >> direction;
    cout << "Enter swap amount: ";
    cin >> shiftCount;

    switch (direction) {
        case 'l': shiftl(array, shiftCount); break;
        case 'r': shiftr(array, shiftCount); break;
        case 'u': shiftu(array, shiftCount); break;
        case 'd': shiftd(array, shiftCount); break;
        default: cout<<error<< "Error command not found \n"; return 0;
    }

    cout << "\n---- Swap result ----:\n"<<outcolor;
    print(array);
}
