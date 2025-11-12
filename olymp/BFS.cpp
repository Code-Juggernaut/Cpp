#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }
    Point(const Point &other) {
        x = other.x;
        y = other.y;
    }
};

int main() {
    int gridSize;
    cin >> gridSize;

    char grid[gridSize][gridSize];
    char pathGrid[gridSize][gridSize];

    int  targetX, targetY;
    int  startX, startY;

  // Чтение карты и определение начальной и целевой точек
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {

            cin >> grid[row][col];
            pathGrid[row][col] = grid[row][col];

            if (grid[row][col] == '@') {
                targetX = col;
                targetY = row;
            } else if (grid[row][col] == 'X') {
                startX = col;
                startY = row;
            }
        }
    }

    queue<struct Point> bfsQueue;
    bfsQueue.push(Point(startX, startY));

  // Поиск пути с помощью BFS
    while (!bfsQueue.empty()) {
        struct Point current = bfsQueue.front();
        bfsQueue.pop();
        int x = current.x, y = current.y;

    // Вправо
        if (x + 1 < gridSize && (grid[y][x + 1] == '.' || grid[y][x + 1] == '@')) {
            grid[y][x + 1] = 'L'; // Left came from
            bfsQueue.push(Point(x + 1, y));
            if (targetX == x + 1 && targetY == y) break;
        }
    // Влево
        if (x - 1 >= 0 && (grid[y][x - 1] == '.' || grid[y][x - 1] == '@')) {
            grid[y][x - 1] = 'R'; // Right came from
            bfsQueue.push(Point(x - 1, y));
            if (targetX == x - 1 && targetY == y) break;
        }
    // Вниз
        if (y + 1 < gridSize && (grid[y + 1][x] == '.' || grid[y + 1][x] == '@')) {
            grid[y + 1][x] = 'U'; // Up came from
            bfsQueue.push(Point(x, y + 1));
            if (targetX == x && targetY == y + 1) break;
        }
    // Вверх
        if (y - 1 >= 0 && (grid[y - 1][x] == '.' || grid[y - 1][x] == '@')) {
            grid[y - 1][x] = 'D'; // Down came from
            bfsQueue.push(Point(x, y - 1));
            if (targetX == x && targetY == y - 1) break;
        }
    }

  // Проверка, достигнута ли цель
    if (grid[targetY][targetX] == '@') {
        cout << 'N';
        return 0;
    } else {
        cout << 'Y' << endl;
        int x = targetX, y = targetY;

    // Восстановление пути
    while (true) {
        pathGrid[y][x] = '+';
        if (grid[y][x] == 'U') y--;
        else if (grid[y][x] == 'L') x--;
        else if (grid[y][x] == 'D') y++;
        else if (grid[y][x] == 'R') x++;

        if (x == startX && y == startY) break;
    }

    pathGrid[targetY][targetX] = '@';
    pathGrid[startY][startX] = '+';

    // Вывод итоговой карты
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            cout << pathGrid[row][col];
        }
        cout << endl;
        }
    }

    return 0;
}
