#include <iostream>
#include <cstdlib>
using namespace std;

void random(int* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 5;
        cout << array[i] << " ";
    }
    cout << endl;
}

// Removes duplicates and returns new size
int filter(int* arr, int size) {
    int* temp = new int[size];
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[newSize++] = arr[i];
        }
    }

    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
    return newSize;
}

int create_min(int* arr1, int size1, int* arr2, int size2, int*& arr_out) {
    size1 = filter(arr1, size1);
    size2 = filter(arr2, size2);

    arr_out = new int[size1 + size2];
    int index = 0;

    for (int i = 0; i < size1; i++) {
        arr_out[index++] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr_out[index++] = arr2[i];
    }

    return filter(arr_out, size1 + size2);
}

int main() {
    int m, n;
    cin >> m >> n;

    int* ptr = new int[m];
    int* ptr2 = new int[n];
    int* ptr3 = nullptr;

    cout << "Array 1: ";
    random(ptr, m);
    cout << "Array 2: ";
    random(ptr2, n);

    int out = create_min(ptr, m, ptr2, n, ptr3);

    cout << "Merged + Filtered: ";
    for (int i = 0; i < out; i++) {
        cout << ptr3[i] << " ";
    }
    cout << endl;

    delete[] ptr;
    delete[] ptr2;
    delete[] ptr3;

    return 0;
}
