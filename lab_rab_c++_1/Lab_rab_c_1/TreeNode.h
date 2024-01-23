#pragma once

template <typename Key, typename Value>
class TreeNode {
public:
    Key key;
    Value value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Key& k, const Value& v);
};

#include "TreeNode.cpp"