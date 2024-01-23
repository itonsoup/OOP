#pragma once
#include "List.h"

using namespace std;

// Определение шаблонного конструктора
template <typename T>
List<T>::Node::Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}

// Определение конструктора для List
template <typename T>
List<T>::List() : head(nullptr) {}

// Определение метода push_back
template <typename T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Определение метода push_front
template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
}

// Определение метода pop_back
template <typename T>
void List<T>::pop_back() {
    if (!head) {
        throw std::runtime_error("List is empty");
    }

    if (!head->next) {
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->prev->next = nullptr;
        delete current;
    }
}

// Определение метода remove
template <typename T>
void List<T>::remove(const T& value) {
    if (!head) {
        std::cerr << "Список пуст. Невозможно удалить значение из списка.\n";
        return;
    }

    Node* current = head;
    while (current) {
        if (current->data == value) {
            if (current->prev) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next) {
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    }

    std::cerr << "Значение не найдено в списке.\n";
}

// Определение метода display
template <typename T>
void List<T>::display() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Определение деструктора
template <typename T>
List<T>::~List() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}