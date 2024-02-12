#include "binary_search_tree.h"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
BST<T>::BST(const BST<T>& oth)
{
    this->root = nullptr;
    if (oth.root) 
    {
        this->root = new TreeNode<T>(*oth.root);
    }
}

template <typename T>
BST<T>::BST(BST<T>&& oth)
{
    this->root = oth.root;
    oth.root = nullptr;
}

template <typename T>
BST<T>::BST(const T& value) : root(new TreeNode<T>(value)) {}

template <typename T>
BST<T>::~BST()
{
    if (root)
    {
        this->clear();
    }
}

template <typename T>
void BST<T>::set_root(TreeNode<T>* new_root)
{
    if (root == new_root)
    {
        return;
    }
    if (root != nullptr)
    {
        clear_helper(root);
        delete root;
    }
    root = new_root;
}

template <typename T>
int BST<T>::get_height() const
{
    if (root == nullptr)
    {
        return -1;
    }
    return get_height_helper(root);
}

template <typename T>
bool BST<T>::is_empty() const
{
    return (root == nullptr);
}

template <typename T>
void BST<T>::insert(const T& value)
{
    root = insert_helper(root, new TreeNode<T>(value));
}

template <typename T>
void BST<T>::remove(T value)
{
    if (root == nullptr || search(value) == false)
    {
        return;
    }
    root = remove_helper(root, value);
}

template <typename T>
bool BST<T>::search(T value) const
{
    if (root == nullptr)
    {
        return false;
    }
    return search_helper(root, value);
}

template <typename T>
void BST<T>::clear()
{
    if (root != nullptr) 
    {
        clear_helper(root);
        delete root;
        root = nullptr;
    }
}

template <typename T>
void BST<T>::display_pre_order() const
{
    if (root == nullptr)
    {
        return;
    }
    display_pre_order_helper(root);
}

template <typename T>
void BST<T>::display_in_order() const
{
    if (root == nullptr)
    {
        return;
    }
    display_in_order_helper(root);
}

template <typename T>
void BST<T>::display_post_order() const
{
    if (root == nullptr)
    {
        return;
    }
    display_post_order_helper(root);
}

template <typename T>
void BST<T>::print()
{
    if (root == nullptr)
    {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }
    print_helper(root, 0);
}

template <typename T>
int BST<T>::get_height_helper(TreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return -1;
    }
    return 1 + std::max(get_height_helper(node->get_left()), get_height_helper(node->get_right()));
}

template <typename T>
TreeNode<T>* BST<T>::insert_helper(TreeNode<T>* node, TreeNode<T>* new_node)
{
    if (node == nullptr) 
    {
        return new_node;
    }
    if (new_node->get_data() < node->get_data()) 
    {
        node->set_left(insert_helper(node->get_left(), new_node));
    } 
    else if (new_node->get_data() > node->get_data()) 
    {
        node->set_right(insert_helper(node->get_right(), new_node));
    }
    return node;

}

template <typename T>
TreeNode<T>* BST<T>::remove_helper(TreeNode<T>* node, T value)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (value < node->get_data())
    {
        node->set_left(remove_helper(node->get_left(), value));
        return node;
    }
    if (value > node->get_data())
    {
        node->set_right(remove_helper(node->get_right(), value));
        return node;
    }
    if (!node->get_left() && !node->get_right())
    {
        delete node;
        return nullptr;
    }
    if (!node->get_left())
    {
        TreeNode<T>* tmp = node->get_right();
        delete node;
        return tmp;
    }
    if (!node->get_right())
    {
        TreeNode<T>* tmp = node->get_left();
        delete node;
        return tmp;
    }
    const TreeNode<T>* tmp = find_min(node->get_left());
    node->set_data(tmp->get_data());
    node->set_left(remove_helper(node->get_left(), tmp->get_data()));
    return node;
}

template <typename T>
TreeNode<T>* BST<T>::find_min(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node->get_left() == nullptr)
    {
        return node;
    }
    return find_min(node->get_left());;
}

template <typename T>
TreeNode<T>* BST<T>::find_max(TreeNode<T>* node)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node->get_right() == nullptr)
    {
        return node;
    }
    return find_max(node->get_right());
}

template <typename T>
bool BST<T>::search_helper(TreeNode<T>* node, T value) const
{
    if (node == nullptr)
    {
        return false;
    }
    if (node->get_data() == value) 
    {
        return true;
    }
    if (value < node->get_data()) 
    {
        return search_helper(node->get_left(), value);
    }
    return search_helper(node->get_right(), value);
}

template <typename T>
void BST<T>::clear_helper(TreeNode<T>* node)
{
    if (node == nullptr) 
    {
        return;
    }
    clear_helper(node->get_left());
    clear_helper(node->get_right());
    delete node;
}

template <typename T>
void BST<T>::display_pre_order_helper(TreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->get_data() << std::endl;
    display_pre_order_helper(node->get_left());
    display_pre_order_helper(node->get_right());
}

template <typename T>
void BST<T>::display_in_order_helper(TreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return;
    }
    display_in_order_helper(node->get_left());
    std::cout << node->get_data() << std::endl;
    display_in_order_helper(node->get_right());
}

template <typename T>
void BST<T>::display_post_order_helper(TreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return;
    }
    display_post_order_helper(node->get_left());
    display_post_order_helper(node->get_right());
    std::cout << node->get_data() << std::endl;
}

template <typename T>
void BST<T>::print_helper(TreeNode<T>* node, int level)
{
    if (node == nullptr)
    {
        return;
    }
    std::cout << node->get_data() << std::endl;
    for (int i = 0; i < level; ++i)
    {
        std::cout << "  ";
    }
    print_helper(node->get_left(), level + 1);
    print_helper(node->get_right(), level + 1);
}
