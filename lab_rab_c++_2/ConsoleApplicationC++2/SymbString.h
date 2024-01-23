#pragma once
#include <iostream>
#include <string>

using namespace std;

class SymbString {
public:
    string identifier;
    string value;

    SymbString(const string& id, const string& val);
    void showValue() const;

    // �������� + ��� SymbString
    SymbString operator+(const SymbString& other) const;
};