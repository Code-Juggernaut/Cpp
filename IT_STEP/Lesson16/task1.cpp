#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    FILE *file;
    file = fopen("file.prog", "w");
    int number = 10;
    char string[] = "hello_world!";
    fprintf(file, "%s %d", string, number);
    fclose(file);

    file = fopen("file.prog", "r");
    number = 0;
    fscanf(file, "%s %d", string, &number);
    cout << number;
    fclose(file);
}
