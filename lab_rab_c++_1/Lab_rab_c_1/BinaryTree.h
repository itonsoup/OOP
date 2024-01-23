#pragma once
#include "TreeNode.h"

template <typename Key, typename Value>
class BinaryTree {
private:
    TreeNode<Key, Value>* root;

    TreeNode<Key, Value>* insert(TreeNode<Key, Value>* node, const Key& key, const Value& value);
    TreeNode<Key, Value>* search(TreeNode<Key, Value>* node, const Key& key) const;
    TreeNode<Key, Value>* findMin(TreeNode<Key, Value>* node) const;
    TreeNode<Key, Value>* remove(TreeNode<Key, Value>* node, const Key& key);
    void traverse(TreeNode<Key, Value>* node, void (*callback)(const Key&, const Value&)) const;

public:
    BinaryTree();
    void insertElement(const Key& key, const Value& value);
    Value searchElement(const Key& key) const;
    void removeElement(const Key& key);
    void displayDictionary() const;
};

#include "BinaryTree.cpp"