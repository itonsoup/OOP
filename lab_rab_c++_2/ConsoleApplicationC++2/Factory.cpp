#include "Factory.h"
#include "SymbString.h"
#include "BinString.h"

using namespace std;

SymbString* Factory::createSymbString(const string& id, const string& val) {
    return new SymbString(id, val);
}

BinString* Factory::createBinString(const string& id, int val) {
    return new BinString(id, val);
}
