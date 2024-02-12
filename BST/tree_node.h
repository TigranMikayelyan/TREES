#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode
{
public:
    TreeNode(); 
    TreeNode(T); 
    ~TreeNode();
public:
    void set_data(T);
    void set_left(TreeNode*);
    void set_right(TreeNode*);
    T get_data() const;
    TreeNode<T>* get_left() const;
    TreeNode<T>* get_right() const;
public:
    void clear();
    bool is_leaf() const;
private:
    T m_data;
    TreeNode<T>* left;
    TreeNode<T>* right;
};

#endif // TREE_NODE_H
