#include <iostream>
#include <stdexcept>
#include <limits> // Для использования numeric_limits
#include "List.h"
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
    setlocale(LC_ALL, "RU");
    try {
        List<int> myList;
        int choice, value;

        do {
            cout << "1. Ввести новое значение в начало списка\n";
            cout << "2. Ввести новое значение в конец списка\n";
            cout << "3. Удалить значение из списка\n";
            cout << "4. Вывести список\n";
            cout << "0. Выйти\n";
            cout << "Выберите действие: ";

            while (!(cin >> choice) || (choice < 0 || choice > 4)) {
                cout << "Допустимые значения команд: 1, 2, 3, 4 или 0. Выберите правильное значение: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            try {
                switch (choice) {
                case 1:
                    cout << "Введите значение: ";
                    while (!(cin >> value)) {
                        cout << "Ошибка ввода. Введите корректное значение: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    myList.push_front(value);
                    cout << endl;
                    break;
                case 2:
                    cout << "Введите значение: ";
                    while (!(cin >> value)) {
                        cout << "Ошибка ввода. Введите корректное значение: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    myList.push_back(value);
                    cout << endl;
                    break;
                case 3:
                    cout << "Введите значение для удаления: ";
                    while (!(cin >> value)) {
                        cout << "Ошибка ввода. Введите корректное значение: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    myList.remove(value);
                    cout << endl;
                    break;
                case 4:
                    cout << "Все значения внутри списка: ";
                    myList.display();
                    cout << endl;
                    break;
                case 0:
                    break;
                }
            }
            catch (const exception& e) {
                cerr << "Ошибка: " << e.what() << endl;
            }
        } while (choice != 0);

    }
    catch (const exception& e) {
        cerr << "Вызванное исключение: " << e.what() << endl;
    }

    return 0;
}