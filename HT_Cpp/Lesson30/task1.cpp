#include<iostream>
#include<string.h>
#include<vector>

/**
 * #     #   ###   ##### #####
 * #   # #  #   #    #   #
 * #  #  #  #   #    #   ####
 * # #   #  #   #    #   #
 * #     #   ###     #   #####
 * 
 * Using stl:vector for string list
 */



using namespace std;
struct Node{
    string number;
    vector<string> fees;
    Node *right;
    Node *left;
    Node(const string &pos,const string &line):
    right(nullptr),left(nullptr),number(pos){
        fees.push_back(line);
    }   
};

class Database{
    private:
    Node *node = nullptr;

    Node *insert(Node *node,const string &num,const string &fee){
        if(!node){
            return new Node(num,fee);
        }
        if(node->number == num){
            node->fees.push_back(fee);
        }else if(num<node->number){
            node->left = insert(node->left,num,fee);
        }else{
            node->right = insert(node->right,num,fee);
        }
        return node;
    }
    Node *search(Node *node,const string &num) const{
        if(!node){
            cout<<"Not found!"<<endl;
            return nullptr;
        }
        if(node->number == num ){
            return node;
        }

        return search((node->number<num?(node->right):(node->left)),num);
    }
    void inorder(Node *node)const {
            if(!node)return;
            inorder(node->left);
            cout<<node->number<<endl;
            for(string i:node->fees){
                cout<<"|-"<<i<<endl;
            }
            inorder(node->right);
        }
    void printrange(Node *node,const string &from,const string &to)const {
        if(!node){
            return;
        }
        if(from<=node->number && to>=node->number){
            cout<<node->number<<endl;
            for(string fee:node->fees){
                cout<<"|-"<<fee<<endl;
            }
            cout<<"+";
        }else{
            return;
        }
        printrange((node->number<to)?(node->right):(node->left),from,to);
    }
    public:
    
        void Insert(const string &num,const string &fee){
            cout<<"---------INSERTING---------"<<endl;
            node = insert(node,num,fee);
        }
        void Search(const string &key)const {
            cout<<"---------SEARCHING---------"<<endl;

            Node *tmp = search(node,key);
            if(tmp == nullptr){
                return;
            }
            for(string data:tmp->fees){
                cout<<data<<endl;
            }
        }
        void Print_all()const {
            cout<<"---------PRINT ALL---------"<<endl;
            inorder(node);
        }
        void print_range(const string &from,const string &to)const {
            cout<<"-------Printing from "<<from<<" to "<<to<<endl;
            printrange(node,from,to);
        }

    };

int main(){
    
    Database data;
    data.Insert("FFFFFF","NAN");
    data.Insert("FFFFFF","NAN1");
    data.Insert("FFFFFF","NAN2");
    data.Search("FFFFFF");
    data.Insert("AFFFFF","NAN");
    data.Insert("BFFFFF","NAN1");
    data.Insert("CFFFFF","NAN2");
    data.Search("EFFFFF");
    data.Print_all();
    data.print_range("AFFFFF","FFFFFF");
}   