#include"header_file.h"
#define size 5 //--------------------------matrix size definition

template <typename templ> 
//--------------------------------------------------------matrix init
void init_matrix(int sizex,templ &array){
    srand(1);
    for(int i = 0 ;i<sizex;i++){
        for(int j = 0;j<sizex;j++){
            array[i][j] = rand()%10;
        }
    }
}
template <typename templ> 
//---------------------------------------------------------matrix print
void print_matrix(int sizex, templ array){
    for(int i = 0;i<sizex;i++){
        for(int j = 0;j<sizex;j++){
            cout<<array[i][j]<<" ";
        }
        cout<<end;
    }
}
template <typename templ> 
//---------------------------------------------------------max and min
void find_max_and_min(int sizex, templ &max ,templ &min,templ array[][size]){
    for(int i = 0;i<sizex;i++){
        if(array[i][i]>max){
            max = array[i][i];
        }
        if(array[i][i]<min){
            min = array[i][i];
        }
    }
}

template <typename templ>
//--------------------------------------------------swap
void swap_overload(templ &master,templ &slave){
    
    if(master<slave){
        templ buffer = master;
        master = slave;
        slave = buffer;
    }
}
template <typename templ>
//------------------------------------------------------------verify
bool verify(int sizex,templ array){
    for(int i = 0;i<sizex;i++){
        int max = array[i][0];
        for(int j = 0;j<sizex;j++){
            if(max<array[i][j]){
                return 0; // if array element<max return INVALID
            }
        }
    }
    return 1; //else return VALID
}

/* !!!---------------NOTE--------------------!!!
    Сортування елементів за зростанням окремо для кожного рядка матриці.
*/

template <typename templ>
//----------------------------------------------------sort
void sort(int sizex, templ &array){
    while(verify(sizex,array) == 0){
        for(int i = 0;i<sizex;i++){
            for(int j = 0;j<sizex-1;j++){
                swap_overload(array[i][j],array[i][j+1]);
            }
        }
    }
}

int main(){
    
    int array[size][size];
    init_matrix(size,array);
    int max = 0;
    int min = array[0][0];
    cout<<error;
    find_max_and_min(size,max,min,array);
    print_matrix(size,array);
    //------------WARNING MAX and MIN founds only before sorted array---------
    sort(size,array);
    cout<<basic;
    print_matrix(size,array);
    cout<<end<<max<<" "<<min;
}