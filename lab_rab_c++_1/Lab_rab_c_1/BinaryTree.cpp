#pragma once
#include "BinaryTree.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree() : root(nullptr) {}

template <typename Key, typename Value>
TreeNode<Key, Value>* BinaryTree<Key, Value>::insert(TreeNode<Key, Value>* node, const Key& key, const Value& value) {
    // Реализация метода insert
    if (node == nullptr) {
        return new TreeNode<Key, Value>(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, value);
    }
    else {
        node->value = value;
    }

    return node;
}

template <typename Key, typename Value>
TreeNode<Key, Value>* BinaryTree<Key, Value>::search(TreeNode<Key, Value>* node, const Key& key) const {
    // Реализация метода search
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

template <typename Key, typename Value>
TreeNode<Key, Value>* BinaryTree<Key, Value>::findMin(TreeNode<Key, Value>* node) const {
    // Реализация метода findMin
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename Key, typename Value>
TreeNode<Key, Value>* BinaryTree<Key, Value>::remove(TreeNode<Key, Value>* node, const Key& key) {
    // Реализация метода remove
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr) {
            TreeNode<Key, Value>* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode<Key, Value>* temp = node->left;
            delete node;
            return temp;
        }

        TreeNode<Key, Value>* temp = findMin(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = remove(node->right, temp->key);
    }

    return node;
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::traverse(TreeNode<Key, Value>* node, void (*callback)(const Key&, const Value&)) const {
    // Реализация метода traverse
    if (node != nullptr) {
        traverse(node->left, callback);
        callback(node->key, node->value);
        traverse(node->right, callback);
    }
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::insertElement(const Key& key, const Value& value) {
    root = insert(root, key, value);
}

template <typename Key, typename Value>
Value BinaryTree<Key, Value>::searchElement(const Key& key) const {
    TreeNode<Key, Value>* node = search(root, key);
    return (node != nullptr) ? node->value : Value();
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::removeElement(const Key& key) {
    root = remove(root, key);
}

template <typename Key, typename Value>
void BinaryTree<Key, Value>::displayDictionary() const {
    traverse(root, [](const Key& key, const Value& value) {
        cout << key << ": " << value << endl;
        });
}