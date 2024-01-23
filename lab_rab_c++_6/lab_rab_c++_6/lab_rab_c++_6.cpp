#include <iostream>
#include <vector>
#include "Point.h"
#include "MazeFunctions.h"
#include <queue>
#include <chrono>



using namespace std;

// Макрос для логгирования времени выполнения
#define LOG_DURATION(message, code) \
    { \
        auto start_time = chrono::high_resolution_clock::now(); \
        code \
        auto end_time = chrono::high_resolution_clock::now(); \
        auto duration = chrono::duration_cast<std::chrono::microseconds>(end_time - start_time); \
        cout << message << ": " << duration.count() << " микросекунд." << endl; \
    }

int main() {
    setlocale(LC_ALL, "RU");

    // визуализация лабиринта
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Point start(1, 1);
    Point end(7, 11);

    vector<Point> shortestPath;


    LOG_DURATION("Время выполнения программы", {
        if (findShortestPath(maze, start, end, shortestPath)) {
            // Вывод самого короткого пути
            cout << "Самый короткий путь:\n";
            printMaze(maze, shortestPath);
        }
 else {
  std::cout << "Путь через лабиринт не найден.\n";
}
        });


    return 0;
}




        
  