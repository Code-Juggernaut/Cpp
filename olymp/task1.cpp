#include <iostream>
#include <queue>
using namespace std;

const int MAX = 20;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(int n, int x1, int y1, int x2, int y2) {
    bool visited[MAX][MAX] = {false};
    int dist[MAX][MAX] = {0};

    queue<pair<int, int>> q;
    q.push({x1, y1});
    visited[x1][y1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == x2 && y == y2){
            return dist[x][y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && ny >= 1 && nx < n && ny < n && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return 0; 
}
int main() {
    int n;
    cin>>n;
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    int result = bfs(n, x1, y1, x2, y2);
    cout << result << endl;

    return 0;
}
