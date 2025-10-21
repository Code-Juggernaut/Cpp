#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;


/*
* Data structure -> graph
*           *home
*           V   V
*        *ap1   *ap2
*       V V     V  V
*    *h1 *h2  *h1 *h2 
*/

class Person{
    private:
        char *_name;
        int _namelen;

    public:
    //======================= CONSTRUCTORS =========
        Person(){
            _name = new char[1];
            _namelen = 1;
        }
        ~Person(){
            delete[] _name;
        }
        // My own realization. See Lesson 22 task1.cpp for details
        Person (const Person &copy){
            _namelen = copy._namelen;
            _name = new char[_namelen];
            strcpy(_name,copy._name);
            //_name[_namelen] = '\0';
            
        }
        Person &operator=(const Person &copy){
            if(this == &copy){
                return *this;
            }
            delete[] _name;
            _namelen = copy._namelen;
            _name = new char[_namelen];
            strcpy(_name,copy._name);
            
            return *this;
        }
    //======================= FUNCTIONS ============
        void edit_name(){
            cout<<"enter human name:";
            delete[] _name;

            _namelen = 1;
            _name = new char[_namelen];
            _name[0] = ' ';
            while(_name[_namelen-1]!='|'){
                scanf(" %c",&_name[_namelen-1]);
                if(_name[_namelen-1]!='|'){
                    _namelen++;
                    char *buffer = new char[_namelen];
                    for(int i =0;i<_namelen-1;i++){
                        buffer[i] = _name[i];
                    }
                    delete[] _name;
                    _name = buffer;
                }
            }
        }
        char *get_name(int *len){
            (*len) = _namelen;
            return _name;
        }

    };
class Apartment{
    private:
        class Person *_array;
        int _array_size;
        char *apartment_name;
        int name_size;
    public:
    //======================= CONSTRUCTORS =========
        Apartment(){
            _array_size = 1;
            _array = new class Person[1];
            _array[0].edit_name();
            apartment_name = new char[1];
            name_size = 1;
        }
        ~Apartment(){
            delete[] _array;
            delete[]apartment_name;
        }
        Apartment(const Apartment &copy){
            _array_size = copy._array_size;
            _array = new class Person [_array_size];
            for(int i = 0;i<_array_size;i++){
                _array[i] = copy._array[i];
            }

            name_size = copy.name_size;
            apartment_name = new char[name_size];
            strcpy(apartment_name,copy.apartment_name);
            
        }
        Apartment &operator=(const Apartment &copy){
            if(this == &copy){
                return *this;
            }
            delete[] _array;
            delete[]apartment_name;
            _array_size = copy._array_size;
            _array = new class Person[_array_size];
            for(int i = 0;i<_array_size;i++){
                _array[i] = copy._array[i];
            }

            name_size = copy.name_size;
            apartment_name = new char[name_size];
            strcpy(apartment_name,copy.apartment_name);
            
            return *this;
        }
    //======================= FUNCTIONS ============
        void add_person(){
            class Person *new_array = new class Person[_array_size+1];
            for(int i = 0;i<_array_size;i++){
                new_array[i] = _array[i];
            }
            new_array[_array_size].edit_name();
            delete[] _array;
            _array = new_array;
            _array_size++;
        }
        void delete_person(int delete_pos){
            class Person *new_array = new class Person[_array_size-1];
            for(int i = 0;i<_array_size-1;i++){
                if(i < delete_pos){
                    new_array[i] = _array[i];
                }else{
                    new_array[i] = _array[i+1];
                }
            }
            _array_size--;
            delete[] _array;
            _array = new_array;
        }
        void print_data(){
            int size;
            
            cout<<"\t";
            for(int i = 0;i<name_size;i++){
                cout<<apartment_name[i];
            }
            
            for(int i = 0;i<_array_size;i++){
                char *pointer = _array[i].get_name(&size);
                cout<<"\t\t";
                for(int i = 0;i<size;i++){
                    cout<<pointer[i];
                }
            }
            cout<<endl;
        }
        void edit_apartment_name(){
            cout<<"enter apartment name:";
            delete[] apartment_name;
            name_size = 1;
            apartment_name = new char[name_size];
            apartment_name[0] = ' ';
            while(apartment_name[name_size-1]!='|'){
                scanf(" %c",&apartment_name[name_size-1]);
                if(apartment_name[name_size-1]!='|'){
                    name_size++;
                    delete[] apartment_name;
                    apartment_name= new char[name_size];
                }
            }
        }
    };
class Building{
    private:
        class Apartment *_array;
        int _array_size;
        char *building_name;
        int name_size;
    public:
    //======================= CONSTRUCTORS =========
        Building(){
            _array = new class Apartment[1];
            _array_size = 1;
            building_name = new char[1];
            name_size = 1;
        }
        ~Building(){
            delete []_array;
            delete []building_name;
        }
        Building(const Building &copy){
            _array_size = copy._array_size;
            _array = new class Apartment[_array_size];
            for(int i = 0;i<_array_size;i++){
                _array[i] = copy._array[i];
            }
            
            name_size = copy.name_size;
            building_name = new char[name_size];
            strcpy(building_name,copy.building_name);
            
        }
        Building &operator=(const Building &copy){
            if(this == &copy){
                return *this;
            }
            delete[] _array;
            delete[] building_name;
            _array_size = copy._array_size;
            _array = new class Apartment[_array_size];
            for(int i = 0;i<_array_size;i++){
                _array[i] = copy._array[i];
            }
            
            name_size = copy.name_size;
            building_name = new char[name_size];
            strcpy(building_name,copy.building_name);
            
            return *this;
        }
    //======================= FUNCTIONS ============
    void add_apartment(){
        class Apartment *new_pointer = new class Apartment[_array_size+1];
        for(int i = 0;i<_array_size;i++){
            new_pointer[i] = _array[i];
        }
        new_pointer[_array_size].add_person();
        delete[] _array;
        _array = new_pointer;
        _array_size++;
    }
    void delete_apartment(int delete_pos){
        class Apartment *new_pointer = new class Apartment[_array_size-1];
        for(int i = 0;i<_array_size-1;i++){
            if(i<delete_pos){
                new_pointer[i] = _array[i];
            }else{
                new_pointer[i] = _array[i+1];
            }
        }
        delete[] _array;
        _array = new_pointer;
        _array_size--;
    }
    void print_data(){

        for(int i = 0;i<name_size;i++){
            cout<<building_name[i];
        }
        cout<<'\n';
        for(int i = 0;i<_array_size;i++){
            cout<<'\t';
            _array[i].print_data();
            
        }
    }
    void edit_building_name(){
        delete[] building_name;
        cout<<"enter building name(| - to end):";
        name_size = 1;
        building_name = new char[name_size];
        building_name[0] = ' ';
        while(building_name[name_size-1]!='|'){
            scanf(" %c",&building_name[name_size-1]);
            if(building_name[name_size-1]!='|'){
                name_size++;
                delete[] building_name;
                building_name= new char[name_size];
            }
        }
    }
};
int main(){
    //============================ IMPORTANT================
    // Chatgpt Generated MAIN
    //============================ IMPORTANT================
    
    cout << "--- Starting Building Simulation (Level 1) ---" << endl;

    // 1. Test Default Constructor (Prompts for Building name and 1st Apartment/Person)
    Building main_building;
    main_building.edit_building_name(); // Edit name immediately to avoid initial ' ' char
    
    cout << "\n--- Current State After Initial Setup (Level 2) ---" << endl;
    main_building.print_data();

    // 2. Test Adding an Apartment (Prompts for 2nd Apartment and its 1st Person)
    cout << "\n--- Adding a Second Apartment (Level 2) ---" << endl;
    main_building.add_apartment();

    cout << "\n--- Current State After Adding Apartment ---" << endl;
    main_building.print_data();

    // 3. Test Deep Copy (Copy Constructor)
    cout << "\n--- Testing Deep Copy via Copy Constructor (Level 3) ---" << endl;
    Building copy_building = main_building; // Uses Building(const Building &copy)

    // Edit the name of the original to prove the copy is independent
    cout << "Editing ORIGINAL building name (to check deep copy):" << endl;
    main_building.edit_building_name();

    cout << "\n--- Original Building After Edit ---" << endl;
    main_building.print_data();

    cout << "\n--- Copied Building (Should retain old name) ---" << endl;
    copy_building.print_data();

    // 4. Test Array Deletion (Removes the first apartment, index 0)
    cout << "\n--- Testing Deletion of Apartment at index 0 (Level 4) ---" << endl;
    main_building.delete_apartment(0);

    cout << "\n--- Original Building After Deletion ---" << endl;
    main_building.print_data();
    
    cout << "\n--- End of Program. Destructors will be called. ---" << endl;
    // The program exits, and destructors for main_building and copy_building are called.
    // If the memory management is fully correct (deep copies/deletions), it will not crash.

    return 0;
}