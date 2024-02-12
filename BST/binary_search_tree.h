#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <exception>
#include <algorithm>

#include "tree_node.h"

template <typename T>
class BST
{
private:
 TreeNode<T>* root;
public:
    BST();
    BST(const BST<T>&);
    BST(BST<T>&&);
    BST(const T&);
    ~BST();
public:
    void set_root(TreeNode<T>*);
    int get_height() const;
    bool is_empty() const;
    void insert(const T&); 
    void remove(T);
    bool search(T) const;
    void clear();
    void display_pre_order() const;
    void display_in_order() const;
    void display_post_order() const;
    void print();
private:
    int get_height_helper(TreeNode<T>*) const;
    TreeNode<T>* insert_helper(TreeNode<T>*, TreeNode<T>*);
    TreeNode<T>* remove_helper(TreeNode<T>*, T);
    TreeNode<T>* find_min(TreeNode<T>*);
    TreeNode<T>* find_max(TreeNode<T>*);
    bool search_helper(TreeNode<T>*, T) const;
    void clear_helper(TreeNode<T>*);
    void display_pre_order_helper(TreeNode<T>*) const;
    void display_in_order_helper(TreeNode<T>*) const;
    void display_post_order_helper(TreeNode<T>*) const;
    void print_helper(TreeNode<T>*, int);
};

#endif // BINARY_SEARCH_TREE_H