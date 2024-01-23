#include "UserInterface.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename Key, typename Value>
void loadDictionaryFromFile(BinaryTree<Key, Value>& dictionary, const string& filename) {
    setlocale(LC_ALL, "Russian");

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    Key key;
    Value value;

    while (file >> key >> value) {
        dictionary.insertElement(key, value);
    }

    file.close();
}

template <typename Key, typename Value>
void userInterface(BinaryTree<Key, Value>& dictionary) {
    // Реализация функции userInterface
    int choice;
    Key key;
    Value value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add word to dictionary\n";
        cout << "2. Remove word from dictionary\n";
        cout << "3. Search for translation\n";
        cout << "4. Display dictionary\n";
        cout << "5. Load dictionary from file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word in English: ";
            cin >> key;
            cout << "Enter translation in Russian: ";
            cin >> value;
            dictionary.insertElement(key, value);
            break;
        case 2:
            cout << "Enter word in English to remove: ";
            cin >> key;
            dictionary.removeElement(key);
            break;
        case 3:
            cout << "Enter word in English to search: ";
            cin >> key;
            cout << "Translation: " << dictionary.searchElement(key) << endl;
            break;
        case 4:
            cout << "Dictionary:\n";
            dictionary.displayDictionary();
            break;
        case 5:
            cout << "Enter filename to load dictionary from: ";
            cin >> value;
            loadDictionaryFromFile(dictionary, value);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}

// Явное создание экземпляра для поддержки шаблонов
template void loadDictionaryFromFile<string, string>(BinaryTree<string, string>&, const string&);

template void userInterface<string, string>(BinaryTree<string, string>&);