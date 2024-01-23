#include "student.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
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

    STUDENT students[10];

    for (int i = 0; i < 10; ++i) {
        cout << "Введите данные о студенте №" << i + 1 << endl;
        students[i].inputStudent();
    }

    LOG_DURATION("Время выполнения сортировки студентов", {
        cout << endl;
        sort(students, students + 10, greater<STUDENT>());
        });

    cout << setw(20) << left << "Фамилия и инициалы" << " | "
        << setw(5) << right << "Группа" << " | "
        << setw(5) << right << "Средний балл" << endl;
    cout << "-----------------------------------------------\n";
    LOG_DURATION("Время выполнения вывода студентов", {
       for (const STUDENT& student : students) {
           if (student.getAverageGrade() >= 4.0f) {
               cout << student << endl;
           }
       }
        });

    return 0;
}