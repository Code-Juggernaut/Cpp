#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

char** Add_rows_to_end(char **array, uint8_t rows, uint8_t cols, char *new_row) {
    char **new_2d_array = (char **)malloc((rows + 1) * sizeof(char *));
    if (!new_2d_array) return NULL;

    // Copy old rows
    for (uint8_t i = 0; i < rows; i++) {
        new_2d_array[i] = (char *)malloc(cols * sizeof(char));
        for (uint8_t j = 0; j < cols; j++) {
            new_2d_array[i][j] = array[i][j];
        }
    }

    // Add new row
    new_2d_array[rows] = (char *)malloc(cols * sizeof(char));
    for (uint8_t j = 0; j < cols; j++) {
        new_2d_array[rows][j] = new_row[j];
    }

    // Free old array
    for (uint8_t i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return new_2d_array;
}

int main() {
    uint8_t rows = 2, cols = 3;
    char **array = (char **)malloc(rows * sizeof(char *));
    for (uint8_t i = 0; i < rows; i++) {
        array[i] = (char *)malloc(cols * sizeof(char));
        for (uint8_t j = 0; j < cols; j++) {
            array[i][j] = i + 1;
        }
    }

    char new_row[3] = {1, 1, 1};
    array = Add_rows_to_end(array, rows, cols, new_row);
    rows++;

    for (uint8_t i = 0; i < rows; i++) {
        for (uint8_t j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (uint8_t i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
