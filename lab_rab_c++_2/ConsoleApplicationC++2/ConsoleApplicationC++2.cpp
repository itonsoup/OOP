#include <iostream>
#include "Factory.h"
#include "SymbString.h"
#include "BinString.h"
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
    system("chcp 1251");

    Factory factory;
    SymbString* symbString1 = nullptr;
    SymbString* symbString2 = nullptr;
    BinString* binString1 = nullptr;
    BinString* binString2 = nullptr;

    string id1, val1, id2, val2, id3, id4;
    int val3, val4;

    int choice;

    do {
        cout << "Главное меню:\n"
            "1. Заполнить данные объектов\n"
            "2. Выполнить сложение\n"
            "3. Удалить объекты\n"
            "0. Выход\n"
            "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << endl;
            // Заполнение данных объектов
            LOG_DURATION("Ввод данных объектов", {
                cout << "Введите ID и значение для SymbString 1: ";
                cin >> id1 >> val1;

                cout << "Введите ID и значение для SymbString 2: ";
                cin >> id2 >> val2;

                cout << "Введите ID для BinString 1 и значение: ";
                cin >> id3 >> val3;

                cout << "Введите ID для BinString 2 и значение: ";
                cin >> id4 >> val4;

                symbString1 = factory.createSymbString(id1, val1);
                symbString2 = factory.createSymbString(id2, val2);
                binString1 = factory.createBinString(id3, val3);
                binString2 = factory.createBinString(id4, val4);
                });
            cout << endl;
            break;

        case 2:
            // Выполнение сложения
            LOG_DURATION("Выполнение сложения", {
                if (symbString1 && symbString2 && binString1 && binString2) {
                    SymbString symbStringResult = *symbString1 + *symbString2;
                    symbStringResult.showValue();

                    BinString binStringResult = *binString1 + *binString2;
                    binStringResult.showValue();
                    cout << endl;
                }
                else {
                    cout << "Объекты не определены. Пожалуйста, сначала заполните данные объектов." << "\n" << endl;
                }
                });
            break;

        case 3:
            // Удаление объектов
            LOG_DURATION("Удаление объектов", {
                if (symbString1 || symbString2 || binString1 || binString2) {
                    if (symbString1) factory.deleteObject(symbString1);
                    if (symbString2) factory.deleteObject(symbString2);
                    if (binString1) factory.deleteObject(binString1);
                    if (binString2) factory.deleteObject(binString2);

                    symbString1 = nullptr;
                    symbString2 = nullptr;
                    binString1 = nullptr;
                    binString2 = nullptr;
                    cout << "Объекты удалены." << "\n" << endl;
                }
                else {
                    cout << "Нет объектов для удаления." << "\n" << endl;
                }
                });
            break;

        case 0:
            // Выход из программы
            break;

        default:
            cout << "Неверный выбор. Пожалуйста, введите правильный вариант." << "\n" << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}