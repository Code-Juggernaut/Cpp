#include<stdio.h>
#include<stdlib.h>

struct Rabbit{
    int ID;
    int howold;
    float weight;
};

int main(){
    FILE *file;
    srand(0);
    file = fopen("program.bin","wb");
    struct Rabbit *array = (struct Rabbit*)malloc(sizeof(struct Rabbit)*15);
    for(int i = 0;i<15;i++){
        array[i].ID = i;
        array[i].howold = rand()%10;
        array[i].weight = (rand()%10)*3.51;
        printf("ID %d age %d weight %.2f \n",array[i].ID,array[i].howold,array[i].weight);
    }
    
    fwrite(array,sizeof(struct Rabbit),15,file);
    fclose(file);
    free(array);

    array = (struct Rabbit*)malloc(sizeof(struct Rabbit)*15);
    file = fopen("program.bin","rb");
    fread(array,sizeof(struct Rabbit),15,file);

    int maxold = 0;
    int maxweight = 0;
    for (int i = 1; i < 15; i++) {
        if (array[i].howold > array[maxold].howold) {
            maxold = i;
        }
    }

    maxweight = maxold;
    for (int i = 0; i < 15; i++) {
        if (array[i].howold == array[maxold].howold && array[i].weight > array[maxweight].weight) {
            maxweight = i;
        }
    }

    printf("the oldest and the heaviest rabbit is year %d weight %.2f at ID %d",array[maxold].howold,array[maxold].weight,array[maxold].ID);
}