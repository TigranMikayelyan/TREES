#ifndef GTREE_H
#define GTREE_H

#include <iostream>
#include <algorithm>

#include "tree_node.h"

template <typename T>
class GeneralTree 
{
public:
    GeneralTree();
    GeneralTree(const T&);
    ~GeneralTree();
public:
    void set_root(TreeNode<T>*);
    TreeNode<T>* get_root() const;
public:
    void insert(TreeNode<T>*, TreeNode<T>*);
    void remove(TreeNode<T>*, TreeNode<T>*);
    void clear();
    bool is_empty() const;
    int get_height();
    bool contains(const T&); 
    void print();
private:
    TreeNode<T>* root;
private:
    void clear_helper(TreeNode<T>*);
    int get_height_helper(TreeNode<T>*);
    bool contains_helper(TreeNode<T>*, T);
    void print_helper(TreeNode<T>*, int);
};

#endif // GTREE_H
