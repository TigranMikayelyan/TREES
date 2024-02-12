#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class TreeNode 
{
public:
    TreeNode(const T&);
    ~TreeNode();
    void set_data(T);
    T get_data() const;
    const std::vector<TreeNode<T>*>& get_children() const;
public:
    void add_child(TreeNode<T>*);
    void remove_child(TreeNode<T>*);
    bool has_children() const;
    int get_num_children() const;
    void clear();
    void print();
private:
    T m_data;
    std::vector<TreeNode<T>*> m_children;
};

#endif // TREE_NODE_H
