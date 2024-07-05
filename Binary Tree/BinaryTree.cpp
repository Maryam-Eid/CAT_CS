#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(int root_value) :
        root(new Node(root_value)) {
}

// Problem #1: Binary Tree Destructor (M)
BinaryTree::~BinaryTree() {
    clear(this->root);
}

void BinaryTree::print_inorder(Node *current) {
    if (!current)
        return;
    print_inorder(current->left);
    cout << current->data << " ";
    print_inorder(current->right);
}

void BinaryTree::print_inorder() {
    print_inorder(root);
    cout << "\n";
}

void BinaryTree::add(vector<int> values, vector<char> direction) {
    assert(values.size() == direction.size());
    Node *current = this->root;
    // iterate on the path, create all necessary nodes
    for (int i = 0; i < (int) values.size(); ++i) {
        if (direction[i] == 'L') {
            if (!current->left)
                current->left = new Node(values[i]);
            else
                assert(current->left->data == values[i]);
            current = current->left;
        } else {
            if (!current->right)
                current->right = new Node(values[i]);
            else
                assert(current->right->data == values[i]);
            current = current->right;
        }
    }
}

// Problem #1: Tree Max
int BinaryTree::tree_max(Node *current) {
    int max_element = current->data;


    if (current->left)
        max_element = max(max_element, tree_max(current->left));

    if (current->right)
        max_element = max(max_element, tree_max(current->right));

    return max_element;

}

// Problem #2: Tree Height
int BinaryTree::tree_height(Node *current) {
    if (!current)
        return 0;

    int left_height = tree_height(current->left);
    int right_height = tree_height(current->right);

    return max(left_height, right_height) + 1;
}


// Problem #3: Count all nodes
int BinaryTree::total_nodes(Node *current) {
    if (!current)
        return 0;

    return 1 + total_nodes(current->left) + total_nodes(current->right);
}

// Problem #4: Count leaf nodes
int BinaryTree::total_leaf_nodes(Node *current) {
    if (!current)
        return 0;

    if (!current->left && !current->right)
        return 1;

    return total_leaf_nodes(current->left) + total_leaf_nodes(current->right);
}

// Problem #5: Search the tree
bool BinaryTree::is_exists(Node *current, int value) {
    if (!current)
        return false;

    if (current->data == value)
        return true;

    return is_exists(current->left, value) || is_exists(current->right, value);
}

// Problem #6: Is Perfect Tree
bool BinaryTree::is_perfect() {
    int height = this->tree_height(this->root);
    int expected = (1 << height) - 1; // 2 ^ height - 1
    return expected == total_nodes(this->root);
}

// Problem #1: Binary Tree Destructor (M)
void BinaryTree::clear(Node *current) {
    if (!current)
        return;

    clear(current->left);
    clear(current->right);

    delete current;
}

// Problem #2: Inorder iterative (M)
void BinaryTree::print_inorder_iterative(Node *current) {
    if (!current)
        return;

    stack<Node *> stack;

    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();

        cout << current->data << " ";

        current = current->right;
    }
    cout << "\n";
}
