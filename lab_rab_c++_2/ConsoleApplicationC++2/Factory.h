#pragma once
#include "SymbString.h"
#include "BinString.h"

using namespace std;

class Factory {
public:
    static SymbString* createSymbString(const string& id, const string& val);
    static BinString* createBinString(const string& id, int val);

    template <typename T>
    static void deleteObject(T* obj);
};

// Определение метода шаблона deleteObject
template <typename T>
void Factory::deleteObject(T* obj) {
    delete obj;
}