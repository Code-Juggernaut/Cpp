#include<iostream>
#include<exception>
#include<stdio.h>


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
    /*void print() const{
        if(is_empty()){
            cout<<"empty"<<endl;
        }
        struct Node *current = head;
        while(current){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }*/
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
    
    /* void rec(){
        print_reverse(head);
    }
    void print_reverse(struct Node *start){
        
        if(start == NULL){
            return;
        }
        print_reverse(start->next);
        cout<<start->data<<" ";
    }*/
    t peek_front()const{
        if(head == NULL){
            throw runtime_error("ERR List EMPTY");
        }
        return head->data;
    }
    bool pop_front(){
        if(!head){
            return 0;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        return 1;
    }
    bool is_contains_top(){
        return head == NULL;
    }
};

template <typename t>

class Stack{
    private:
        Linked_list<t> list;
    public:
        void push(const t &val){
            list.push_front(val);
        }
        bool pop(){
            if(list.is_contains_top()){
                return 0;
            }
            
            return list.pop_front();
        }
        t top() const{
            return list.peek_front();
        }
        bool is_empty() const{
            return list.is_empty();
        }
        void print()const{
            cout<<"stack:";
            //list.print();
        }
};

template <typename t>
class Queue{
    private:
        Linked_list<t> list;
    public:
        void push(t &value){
            list.push_back(value);
        }
        t front(){
            return list.peek_front();
        }
        bool pop(){
            return list.pop_front();
        }
        bool is_empty(){
            return list.is_empty();
        }
        void print(){
            Linked_list<t> temp;
            while(!list.is_empty()){
                temp.push_back(list.peek_front());
               // cout<<list.peek_front()<<" ";
                list.pop_front();
            }
            while(!temp.is_empty()){
                list.push_back(temp.peek_front());
                temp.pop_front();
            }
        }
};


class History{
    private:
        Stack<string> history;
    public:
        void visit(const string &url){
            history.push(url);
        }
        void back(){
            if(!history.is_empty()){
                history.pop();
            }
        }
        string get_page() const{
            return (history.is_empty()== 1?("NAN"):(history.top()));
        }
};


struct pasager{
    string name;
    string surname;
};

template <typename t>
class Bus{
    private:
        Queue<t> list;
    public:
        void arrive(t value){
            list.push(value);
        }
        void board(){
            if(list.is_empty()== 0){
                list.pop();
            }
            
        }
        t next(){
            if(list.is_empty() == 0){
                return list.front();
            }
            return {"NAN","NAN"};
        }
        void show_last(){
            cout<<"remaining: "<<endl;
            
            struct pasager buffer;
            if(list.is_empty() == 0){
                list.print();
                buffer = list.front();
            }
            
            cout<<"next: "<<buffer.name<<" "<<buffer.surname<<endl;

        }
};
int main(){
    /*try{
        Stack<int> _lifo;
        for(int i = 0;i<10;i++){
            _lifo.push(i);
        }
        _lifo.print();
        for(int i = 0;i<10;i++){
            cout<<_lifo.top()<<endl;
            _lifo.pop();
        }

        Queue<int> _fifo;
        for(int i = 0;i<10;i++){
            _fifo.push(i);
        }
        _fifo.print();
        for(int i = 0;i<10;i++){
            _fifo.pop();
        }
        _fifo.print();
    }
    catch(runtime_error &error){
        cout<<error.what();
    }

    History browser;
    browser.visit("google.com");
    browser.visit("st.community.com");
    browser.visit("geeksforgeeks.com");
    browser.visit("github.com");
    browser.visit("eax.me");
    cout<<browser.get_page()<<endl;
    browser.back();
    cout<<browser.get_page()<<endl;
*/
    Bus<struct pasager> bus;
    for(int i = 0;i<5;i++){
        struct pasager buffer;
        cin>>buffer.name>>buffer.surname;
        bus.arrive(buffer);
        
    }
    for(int i = 0;i<5;i++){
        bus.show_last();
        cout<<endl;
        bus.next();
        bus.board();
        bus.show_last();
    }
}