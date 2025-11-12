#include<iostream>
#include<stdint.h>
using std::cout;

struct UserPremit{
    uint32_t read:2;
    uint32_t write:2;
    uint32_t execute:2;

    void get_rights(){
        cout<<read;
        cout<<write;
        cout<<execute;
    }
};
int main(){
    struct UserPremit admin = {3,3,3};
    struct UserPremit guest = {0,0,0};
    cout<<sizeof(admin);
    admin.get_rights();
    guest.get_rights();
}