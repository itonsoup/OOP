#pragma once
#include "TreeNode.h"

template <typename Key, typename Value>
TreeNode<Key, Value>::TreeNode(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr) {};