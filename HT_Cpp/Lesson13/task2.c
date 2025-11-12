#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Введення двовимірного масиву з клавіатури
int* inputMatrix(char name, int* totalSize) {
    int rows, cols;
    printf("enter howmany rows %c: ", name);
    scanf("%d", &rows);
    printf("enter howmany cols %c: ", name);
    scanf("%d", &cols);

    *totalSize = rows * cols;
    int* matrix = (int*)malloc((*totalSize) * sizeof(int));
    if (!matrix) {
        printf("ERROR\n");
        return NULL;
    }

    
    for (int i = 0; i < *totalSize; i++) {
        matrix[i] = rand()%20;
    }

    return matrix;
}

// Перевірка наявності значення в масиві
int contains(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return 1;
    return 0;
}

// Додавання унікального значення
void addUnique(int* arr, int* size, int value) {
    if (!contains(arr, *size, value)) {
        arr[*size] = value;
        (*size)++;
    }
}

// Вивід масиву
void printArray(const char* label, int* arr, int size) {
    printf("%s: ", label);
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int sizeA, sizeB, sizeC;
    int *A = inputMatrix('A', &sizeA);
    int *B = inputMatrix('B', &sizeB);
    int *C = inputMatrix('C', &sizeC);

    int *commonABC = (int*)malloc(MAX_SIZE * sizeof(int));
    int *uniqueABC = (int*)malloc(MAX_SIZE * sizeof(int));
    int *commonAC = (int*)malloc(MAX_SIZE * sizeof(int));
    int *negativeValues = (int*)malloc(MAX_SIZE * sizeof(int));
    int sizeCommonABC = 0, sizeUniqueABC = 0, sizeCommonAC = 0, sizeNegative = 0;

    // Унікальні значення
    for (int i = 0; i < sizeA; ++i) addUnique(uniqueABC, &sizeUniqueABC, A[i]);
    for (int i = 0; i < sizeB; ++i) addUnique(uniqueABC, &sizeUniqueABC, B[i]);
    for (int i = 0; i < sizeC; ++i) addUnique(uniqueABC, &sizeUniqueABC, C[i]);

    // Загальні значення для A, B, C
    for (int i = 0; i < sizeA; ++i) {
        int val = A[i];
        if (contains(B, sizeB, val) && contains(C, sizeC, val)) {
            addUnique(commonABC, &sizeCommonABC, val);
        }
    }

    // Спільні значення для A і C
    for (int i = 0; i < sizeA; ++i) {
        if (contains(C, sizeC, A[i])) {
            addUnique(commonAC, &sizeCommonAC, A[i]);
        }
    }

    // Від'ємні значення без повторень
    for (int i = 0; i < sizeA; ++i)
        if (A[i] < 0) addUnique(negativeValues, &sizeNegative, A[i]);
    for (int i = 0; i < sizeB; ++i)
        if (B[i] < 0) addUnique(negativeValues, &sizeNegative, B[i]);
    for (int i = 0; i < sizeC; ++i)
        if (C[i] < 0) addUnique(negativeValues, &sizeNegative, C[i]);

    // Вивід результатів
    printArray("\nCommons for A, B, C", commonABC, sizeCommonABC);
    printArray("Unique for A, B, C", uniqueABC, sizeUniqueABC);
    printArray("commons for A and C", commonAC, sizeCommonAC);
    printArray("Neg values", negativeValues, sizeNegative);

    // Звільнення пам'яті
    free(A);
    free(B);
    free(C);
    free(commonABC);
    free(uniqueABC);
    free(commonAC);
    free(negativeValues);

    return 0;
}
