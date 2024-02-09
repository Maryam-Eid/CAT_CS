#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data{};
    Node *next{};

    Node(int data) : data(data) {}

    ~Node();
};

class LinkedList {
private:
    Node *head{};
    Node *tail{};
    int length = 0;
    vector<Node *> debug_data;

    void debug_add_node(Node *node);

    void debug_remove_node(Node *node);

public:
    LinkedList();

    ~LinkedList();

    LinkedList(const LinkedList &) = delete;

    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address();

    void debug_print_node(Node *node, bool is_separate = false);

    void debug_print_list(string msg = "");

    string debug_to_string();

    void debug_verify_data_integrity();

    void print();

    void delete_node(Node *node);

    void add_node(Node *node);

    void insert_end(int value);

    void insert_front(int value);

    void delete_front();

    Node *get_nth(int n);

    Node *get_nth_back(int n);

    bool is_same(const LinkedList &other);

    bool is_same2(const LinkedList &other);

    void print6();

    void add_element(int value);

    Node *get_tail();

    void delete_node_with_key(int value);

    void swap_pairs();

    void reverse();

    void delete_even_positions();

    void insert_sorted(int value);

    void swap_head_tail();

    void left_rotate(int k);


};

