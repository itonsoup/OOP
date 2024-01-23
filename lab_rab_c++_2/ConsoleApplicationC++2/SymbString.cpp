#include "SymbString.h"

using namespace std;

SymbString::SymbString(const string& id, const string& val) : identifier(id), value(val) {}

void SymbString::showValue() const {
    cout << "SymbString " << identifier << ": " << value << endl;
}

// Реализация оператора +
SymbString SymbString::operator+(const SymbString& other) const {
    SymbString result = *this;
    result.value += " " + other.value;
    return result;
}