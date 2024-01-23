#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
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
    system("chcp 1251"); // кодировка консоли, помогло получить русский язык

    // Запросить пользователя ввести слово для поискат
    cout << "Введите слово для поиска: ";
    string searchWord;
    cin >> searchWord;

    // Открыть файл для чтения
    ifstream inputFile("lab_5.txt"); 

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл!" << endl;
        return 1;
    }

    string line;
    bool found = false; // Флаг для отслеживания наличия искомого слова в файле
    
    LOG_DURATION("Время выполнения поиска в файле", {
       while (getline(inputFile, line)) {
           // Привести всю строку и искомое слово к нижнему регистру для учета регистра
           transform(line.begin(), line.end(), line.begin(), ::tolower);
           transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

           // Проверить, содержит ли строка искомое слово
           if (line.find(searchWord) != string::npos) {
               // Вывести предложение на экран
               cout << line << endl;
               found = true; // Искомое слово найдено
           }
       }
        });

    // Проверить, было ли найдено искомое слово
    if (!found) {
        cerr << "Слово '" << searchWord << "' не найдено в файле." << endl;
    }

    
    


    // Закрыть файл
    inputFile.close();

    return 0;
}