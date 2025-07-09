#include<iostream>
#define newli
#if defined(newlib)
    #define NEWLIB_STATE "ACTIVE"
#else
    #define NEWLIB_STATE "DISABLED"
#endif
#ifndef macro
#define macro __DATE__
#endif
using namespace std;

int main(){
    cout<<macro;
    cout<<NEWLIB_STATE;
}