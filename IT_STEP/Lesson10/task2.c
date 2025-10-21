#include<stdint.h>
#include<stdio.h>

float sum(int a,int b){
    return a+b;
}
float div(int a,int b){
    return b!=0? a/b: 0xEE;
}
float minus(int a,int b){
    return a-b;
}
float multiple(int a,int b){
    return a*b;
}
void calc(int x,int y, float(*operand)(int,int)){
    printf("Result : %.3f",operand(x,y));
}
float (*getOperation(char operation))(int,int){
    switch(operation){
        case '+':return &sum;break;
        case '-':return &minus;break;
        case '*':return &multiple;break;
        case '/':return &div;break;
        default:return NULL;break;
        
    }
}

int main() {
    int array[2];
    char operand;

    printf("\033[93m Enter numbers and operation (e.g., 12 - 3): ");
    scanf("%d %c %d", &array[0], &operand, &array[1]);

    float (*operation)(int, int) = getOperation(operand);
    if (operation == NULL) {
        printf("\033[91m ERROR: Invalid operator\n");
    } else {
        printf("Out: %.3f\n", operation(array[0], array[1]));
    }

    return 0;
}

