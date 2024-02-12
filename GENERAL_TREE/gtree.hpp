#include "gtree.h"

template <typename T>
GeneralTree<T>::GeneralTree() : root(nullptr) {}

template <typename T>
GeneralTree<T>::GeneralTree(const T& root_data) : root(new TreeNode<T>(root_data)) {}

template <typename T>
GeneralTree<T>::~GeneralTree()
{
    clear();
}

template <typename T>
void GeneralTree<T>::set_root(TreeNode<T>* new_root)
{
    root = new_root;
}

template <typename T>
TreeNode<T>* GeneralTree<T>::get_root() const
{
    return root;
}

template <typename T>
void GeneralTree<T>::insert(TreeNode<T>* parent, TreeNode<T>* child)
{
    if (parent == nullptr)
    {
        std::cout << "Cannot insert under a null parent." << std::endl;
        return;
    }
    parent->add_child(child);
}

template <typename T>
void GeneralTree<T>::remove(TreeNode<T>* parent, TreeNode<T>* child)
{
    if (parent == nullptr)
    {
        std::cout << "Cannot remove from a null parent." << std::endl;
        return;
    }
    parent->remove_child(child);
}

template <typename T>
void GeneralTree<T>::clear()
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return;
    }
    clear_helper(root);
    root = nullptr;
}

template <typename T>
bool GeneralTree<T>::is_empty() const
{
    return (root == nullptr);
}

template <typename T>
int GeneralTree<T>::get_height()
{
    if (root == nullptr)
    {
        return 0;
    }
    return get_height_helper(root);
}

template <typename T>
bool GeneralTree<T>::contains(const T& value)
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty" << std::endl;
        return false;
    }
    return contains_helper(root, value);
}

template <typename T>
void GeneralTree<T>::print()
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty." << std::endl;
        return;
    }
    print_helper(root, 0);
}


template <typename T>
void GeneralTree<T>::clear_helper(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }
    for (TreeNode<T>* child : node->get_children())
    {
        clear_helper(child);
    }
    delete node;
    node = nullptr;
}

template <typename T>
int GeneralTree<T>::get_height_helper(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int max_height = 0;
    for (TreeNode<T>* child : node->get_children())
    {
        int child_height = get_height_helper(child);
        max_height = std::max(max_height, child_height);
    }
    return max_height + 1;
}

template <typename T>
bool GeneralTree<T>::contains_helper(TreeNode<T>* node, T value)
{
    if (node == nullptr)
    {
        return false;
    }
    if (value == node->get_data())
    {
        return true;
    }
    for (TreeNode<T>* child : node->get_children())
    {
        if (contains_helper(child, value))
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void GeneralTree<T>::print_helper(TreeNode<T>* node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    std::cout << node->get_data() << std::endl;
    for (TreeNode<T>* child : node->get_children())
    {
        print_helper(child, level + 1);
    }
}
