#include "MazeFunctions.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isValid(int row, int col, const vector<vector<int>>& maze) {
    // Проверка на допустимость координат
    return row >= 0 && row < static_cast<int>(maze.size()) &&
        col >= 0 && col < static_cast<int>(maze[0].size()) && maze[row][col] == 1;
}

bool findShortestPath(const vector<vector<int>>& maze, Point start, Point end, vector<Point>& path) {
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));

    // Используем очередь для алгоритма поиска в ширину
    queue<Point> queue;
    queue.push(start);

    // Мапа для хранения предыдущих точек на пути
    vector<vector<Point>> prev(maze.size(), vector<Point>(maze[0].size(), Point(-1, -1)));

    while (!queue.empty()) {
        Point current = queue.front();
        queue.pop();

        int row = current.row;
        int col = current.col;

        // Если достигли конечной точки, строим путь и завершаем поиск
        if (row == end.row && col == end.col) {
            path.clear();
            while (!(current == start)) {
                path.push_back(current);
                current = prev[current.row][current.col];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return true;
        }

        // Добавляем соседей в очередь для дальнейшего исследования
        if (isValid(row - 1, col, maze) && !visited[row - 1][col]) {
            queue.push(Point(row - 1, col));
            visited[row - 1][col] = true;
            prev[row - 1][col] = current;
        }
        if (isValid(row + 1, col, maze) && !visited[row + 1][col]) {
            queue.push(Point(row + 1, col));
            visited[row + 1][col] = true;
            prev[row + 1][col] = current;
        }
        if (isValid(row, col - 1, maze) && !visited[row][col - 1]) {
            queue.push(Point(row, col - 1));
            visited[row][col - 1] = true;
            prev[row][col - 1] = current;
        }
        if (isValid(row, col + 1, maze) && !visited[row][col + 1]) {
            queue.push(Point(row, col + 1));
            visited[row][col + 1] = true;
            prev[row][col + 1] = current;
        }
    }

    // Путь не найден
    return false;
}

void printMaze(const vector<vector<int>>& maze, const vector<Point>& path) {
    for (int i = 0; i < static_cast<int>(maze.size()); ++i) {
        for (int j = 0; j < static_cast<int>(maze[i].size()); ++j) {
            if (maze[i][j] == 1) {
                // Открытый путь
                if (find(path.begin(), path.end(), Point(i, j)) != path.end()) {
                    // Путь проходит через этот квадрат
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }
            else {
                // Закрытый путь
                cout << "# ";
            }
        }
        cout << endl;
    }
}