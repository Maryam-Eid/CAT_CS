#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;


class BinaryTree {
public:
    struct Node {
        int data{};
        Node *left{};
        Node *right{};

        Node(int data) : data(data) {}
    };

    Node *root{};

    void print_inorder(Node *current);

    BinaryTree(int root_value);

    ~BinaryTree();

    void add(vector<int> values, vector<char> direction);

    int tree_max(Node *root);

    int tree_height(Node *root);

    int total_nodes(Node *root);

    int total_leaf_nodes(Node *root);

    bool is_exists(Node *current, int value);

    bool is_perfect();

    void clear(Node *root);

    void print_inorder_iterative(Node *root);
};


#endif
