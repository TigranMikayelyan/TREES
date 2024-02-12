#include "tree_node.h"

template <typename T>
TreeNode<T>::TreeNode(const T &val) : m_data(val) {}

template <typename T>
TreeNode<T>::~TreeNode()
{
    clear();
}

template <typename T>
void TreeNode<T>::set_data(T val)
{
    m_data = val;
}

template <typename T>
T TreeNode<T>::get_data() const
{
    return m_data;
}

template <typename T>
const std::vector<TreeNode<T>*>& TreeNode<T>::get_children() const
{
    return m_children;
}

template <typename T>
void TreeNode<T>::add_child(TreeNode<T>* child)
{
    m_children.push_back(child);
}

template <typename T>
void TreeNode<T>::remove_child(TreeNode<T>* child)
{
    auto it = m_children.begin();
    while (it != m_children.end()) 
    {
        if (*it == child) 
        {
            it = m_children.erase(it);
            return;
        }
        ++it;
    }
}

template <typename T>
bool TreeNode<T>::has_children() const
{
    return m_children.empty();
}

template <typename T>
int TreeNode<T>::get_num_children() const
{
    return m_children.size();
}

template <typename T>
void TreeNode<T>::clear()
{
    m_children.clear();
    m_data = T();
}

template <typename T>
void TreeNode<T>::print()
{
    for (auto i : m_children)
    {
        std::cout << i->m_data << " ";
    }
    std::cout << std::endl;
}
