#include "tree_node.h"

template <typename T>
TreeNode<T>::TreeNode() : 
m_data(T()),
left(nullptr),
right(nullptr)
{}

template <typename T>
TreeNode<T>::TreeNode(T value) : 
m_data(value), 
left(nullptr), 
right(nullptr) 
{}

template <typename T>
TreeNode<T>::~TreeNode()
{
    this->clear();
}

template <typename T>
void TreeNode<T>::set_data(T data)
{
    this->m_data = data;
}  

template <typename T>
void TreeNode<T>::set_left(TreeNode* new_left)
{
    this->left = new_left;
}

template <typename T>
void TreeNode<T>::set_right(TreeNode* new_right)
{
    this->right = new_right;
}

template <typename T>
T TreeNode<T>::get_data() const
{
    return m_data;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_left() const
{
    return left;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_right() const
{
    return right;
}

template <typename T>
void TreeNode<T>::clear()
{
    if (left == nullptr || right == nullptr)
    {
        return;
    }
    m_data = T();
    if (left != nullptr)
    {
        delete left;
        left = nullptr;
    }
    if (right != nullptr)
    {
        delete right;
        right = nullptr;
    }
}

template <typename T>
bool TreeNode<T>::is_leaf() const
{
    return (left == nullptr && right == nullptr);
}

