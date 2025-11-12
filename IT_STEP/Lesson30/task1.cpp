#include<iostream>
#include<stdlib.h>
#include<chrono>
#include<ctime>

using namespace std;
using namespace std::chrono;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val),left(nullptr),right(nullptr){

    }
};
//Binnary tree search
class BST{
    private:
        Node *insertRecursive(Node * node, int data){
            if(!node){
                return new Node(data);
            }
            if(data<node->data){
                node->left = insertRecursive(node->left, data);
            }else{
                node->right = insertRecursive(node->right,data);
            }
            return node;
        }
        bool searchRecursive(Node *node,int data){
            if(!node) return 0;
            if(data == node->data){
                return 1;
            }
            return searchRecursive((data < node->data ? node->left : node->right), data);
        }
        void inorderRecursive(Node *node){
            if(!node)return;
            inorderRecursive(node->left);
            cout<<node->data<<" ";
            inorderRecursive(node->right);
        }
    public:
    Node* root= nullptr;
        void insert(int data){
            root= insertRecursive(root,data);
        }
        bool search(int data){
            return searchRecursive(root,data);
        }
        void inorder(){
            inorderRecursive(root);
            cout<<endl;
        }
        int findmin(Node *node){
            if(!node)return -1;
            
            while(node->left){
                node = node->left;
            }
            return node->data;
        }
        int findmax(Node *node){
            if(!node)return -1;
            
            while(node->right){
                node = node->right;
            }
            return node->data;


        }
    };      


bool linear_search(const int arr[], int size, int search){
    for(int i = 0;i<size;i++){
        if(arr[i] == search){
            return 1;
        }
    }
    return 0;
}

const long int SIZE = 100000;
int Array[SIZE] = {0};

int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    BST binary_tree;
    // for(int i = 0;i<10;i++){
    //     binary_tree.insert(rand()%100);
    // }
    binary_tree.inorder();
    for(int i = 0;i<10;i++){
        //Array[i] = rand()%1000;
        binary_tree.insert(Array[i]);
    }
    cout<<"max = "<<binary_tree.findmax()<<endl;
    cout<<"max = "<<binary_tree.findmin()<<endl;
    /*int target = Array[SIZE/2]; 

    auto start1 = high_resolution_clock::now();
    bool found1 = linear_search(Array,SIZE,target);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(end1 - start1);



    auto start2 = high_resolution_clock::now();
    bool found2 = binary_tree.search(target);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(end2 - start2);
    cout<<"linear: "<<duration1.count()<<" binary: "<<duration2.count();*/
}