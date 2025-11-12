#include<iostream>

using namespace std;

template <typename t>
class Linked_list{
    private:
        
        struct Node{
            t data;
            Node *next;
            Node(const t &val):data(val),next(NULL){
                
            }
            Node(){

            }
        };
        Node *head;
    public:
    Linked_list():head(NULL){

    }
    void push_front(const t &value){
        struct Node *new_node = new struct Node(value);
        new_node ->next = head;
        head = new_node;
    }
    void push_back(const t &value){
        struct Node *new_node = new struct Node(value);
        if(!head){
            head = new_node;
            return;
        }
        struct Node *current = head;
        while(current->next){
            current = current->next;
        }
        current->next = new_node;
    }
    bool is_empty() const{
        return head == NULL;
    }
    void print() const{
        if(is_empty()){
            cout<<"empty"<<endl;
        }
        struct Node *current = head;
        while(current){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    void clear(){
        struct Node *current = head;
        while(head!= NULL){
            current = head;
            head = head->next;
            delete current;
        }
    }
    bool insert_after(const t &where, const t &value){
        struct Node *current = head;
        while(current){
            if(current->data == where){
                struct Node *new_node = new struct Node(value);
                new_node->next = current->next;
                current->next = new_node;
                return 1;
            }
            current = current->next;
        }
        return 0;
    }
    bool insert_before(const t &where, const t &value){
        if(!head){
            return 0;
        }
        if(head->data == where){
            push_front(value);
            return 1;
        }
        struct Node *current = head;
        struct Node *prev = NULL;
        while(current){
            if(current->data == where){
                struct Node *new_node = new struct Node(value);
                new_node->next = current;
                if(prev){
                    prev->next = new_node;
                }
                return 1;
            }
            prev = current;
            current = current->next;
            
        }
        return 0;
    }
    bool remove(const t &where){
        struct Node *current = head;
        struct Node *prev = NULL;
        while(current){
            if(current->data == where){
                if(prev){
                    prev->next = current->next;
                }else{
                    head = current->next;
                }
                delete current;
                return 1;
            }
            prev = current;
            current = current->next;
        }
        return 0;
    }
    
    void rec(){
        print_reverse(head);
    }
    void print_reverse(struct Node *start){
        
        if(start == NULL){
            return;
        }
        print_reverse(start->next);
        cout<<start->data<<" ";
    }
};


int main(){
    Linked_list<int> object;
    object.push_front(10);
    object.print();
    object.push_front(20);
    object.print();
    object.push_back(30);
    
    object.print();
    object.push_back(40);
    object.print();
    object.insert_after(30,100);
    object.insert_before(20,2431);
    object.remove(40);
    object.print();
    object.rec();
    object.clear();
    object.print();

}