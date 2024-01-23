#pragma once

#include <iostream>


template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value);
    };

    Node* head;

public:
    List();  // ќбъ€вление шаблонного конструктора
    void push_back(const T& value);
    void push_front(const T& value);
    void pop_back();
    void remove(const T& value);
    void display() const;
    ~List();
};

#include "List.cpp"  // ¬кл. определени€ методов из отдельного файла