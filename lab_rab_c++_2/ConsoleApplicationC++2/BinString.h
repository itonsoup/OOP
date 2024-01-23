#pragma once
#include <string>

using namespace std;

class BinString {
public:
    string identifier;
    int value;

    BinString(const string& id, int val);
    void showValue() const;

    // Оператор + для BinString
    BinString operator+(const BinString& other) const;
};