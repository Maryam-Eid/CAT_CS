#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data{};
    Node *next{};
    Node *prev{};

    Node(int data) : data(data) {}

    void set(Node *next, Node *prev) {
        this->next = next;
        this->prev = prev;
    }

    ~Node() {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
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

    void print_reversed();

    void delete_all_nodes_with_key(int value);

    void delete_even_positions();

    void delete_odd_positions();

    bool is_palindrome();

    Node *find_middle();

    Node *find_middle2();

    void swapForwardWithBackward(int k);

    void swapForwardWithBackward2(int k);

    void reverse();

    void merge_2sorted_lists(LinkedList &other);


};

