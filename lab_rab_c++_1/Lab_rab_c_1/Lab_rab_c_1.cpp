#include <iostream>
#include "UserInterface.h"
#include <chrono>

using namespace std;

// Макрос для логгирования времени выполнения
#define LOG_DURATION(message, code) \
    { \
        auto start_time = chrono::high_resolution_clock::now(); \
        code \
        auto end_time = chrono::high_resolution_clock::now(); \
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time); \
        cout << message << ": " << duration.count() << " микросекунд." << endl; \
    }

int main() {
    system("chcp 1251");
    BinaryTree<string, string> englishToRussianDictionary;

    // Вызов пользовательского интерфейса с макросом LOG_DURATION
    LOG_DURATION("Время выполнения пользовательского интерфейса", {
        userInterface(englishToRussianDictionary);
        });

    return 0;
}