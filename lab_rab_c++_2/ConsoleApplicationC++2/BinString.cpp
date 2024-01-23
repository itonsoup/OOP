#include "BinString.h"
#include <iostream>

using namespace std;

BinString::BinString(const string& id, int val) : identifier(id), value(val) {}

void BinString::showValue() const {
    cout << "BinString " << identifier << ": " << value << endl;
}

// Реализация оператора +
BinString BinString::operator+(const BinString& other) const {
    BinString result = *this;
    result.value += other.value;
    return result;
}