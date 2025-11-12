#include<iostream>
#include<queue>

using namespace std;
// No 982,996

struct _queue_data{
    int vertex;
    int step;
};
int main(){
    int nodes;    
    cin>>nodes;
    int array[nodes+1][nodes+1] = {0};
    for(int i = 1;i<=nodes;i++){
        for(int j = 1;j<=nodes;j++){
            cin>>array[i][j];
        }
    }
    int start_node,end_node;
    cin>>start_node>>end_node;

    int merge_table[nodes+1] = {0};
    queue<_queue_data> q;
    bool is_found = 0;

    q.push({start_node,0});
    merge_table[start_node] = 1;

    _queue_data buffer;
    if(start_node == end_node){
        cout<<0;
        return 0;
    }
    while(!is_found && !q.empty()){
        buffer = q.front();
        q.pop();
        for(int i = 1;i<=nodes;i++){
            if(array[buffer.vertex][i] == 1 && merge_table[i]== 0){
                merge_table[i] = 1;
                _queue_data temp;
                temp.vertex = i;
                temp.step = buffer.step+1;
                q.push(temp);
                if(i==end_node){
                    is_found = 1;
                    break;
                }
            }
        }
    }
    
    if(is_found == 1){
        buffer = q.back();
        cout<<buffer.step;
    }else{
        cout<<-1;
    }
}
