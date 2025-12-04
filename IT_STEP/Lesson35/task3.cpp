#include<iostream>
#include<memory>
#include<string>

using namespace std;

struct Item{
    string name;
    int quantity;
};

class Inventory{
    private:
        unique_ptr<Item> _items[10];
        int _size;
    public:
        Inventory(int size,Item *items):_size(size){
            for(int i = 0;i<size;i++){
                _items[i] = make_unique<Item>(items[i]);
            }
        }
        Item getItem(const int pos){
            struct Item buffer;
            buffer.name = _items[pos]->name;
            buffer.quantity = _items[pos]->quantity;
            _size--;
            return buffer;
        }
        void add_item(const struct Item item){
            if(_size<10){
                _items[_size] = make_unique<Item>(item);
                _size++;
            }
        }
        void showItems(){
            for(int i = 0;i<_size;i++){
                cout<<_items[i]->name<<endl;
            }
        }
};

class Player{
    private:
        shared_ptr<Inventory> items;
        
    public:
        Player(shared_ptr<Inventory> inventory) : items(inventory) {}

        void getInventory(){
            items->showItems();
        }
};

class Stats{
    private:
        weak_ptr<Player> players[10];
    public:
        void add(shared_ptr<Player> data,int index){
            players[index] = data;
        }
        void show(){
            for(int i  =0;i<10;i++){
                if(auto data = players[i].lock()){
                    data->getInventory();
                }else{
                    cout<<"empty"<<endl;
                }
            }
        }

};

int main(){
    Item items[3] = {
        {"Sword", 1},
        {"Potion", 5},
        {"Shield", 1}
    };

    // Create inventory
    auto inv = make_shared<Inventory>(3, items);

    // Create player with inventory
    auto player = make_shared<Player>(inv);

    // Create stats and add player
    Stats stats;
    stats.add(player, 0);

    // Show stats (which shows player inventory)
    stats.show();

    return 0;
}