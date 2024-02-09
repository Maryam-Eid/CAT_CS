#include "SLL.h"
#include <cassert>
#include <sstream>
#include <algorithm>

using namespace std;

Node::~Node() {
    cout << "Destroy value: " << data << " at address " << this << "\n";
}

LinkedList::LinkedList() {
}

void LinkedList::debug_add_node(Node *node) {
    debug_data.push_back(node);
}

void LinkedList::debug_remove_node(Node *node) {
    auto it = find(debug_data.begin(), debug_data.end(), node);
    if (it == debug_data.end())
        cout << "Node does not exist\n";
    else
        debug_data.erase(it);
}

void LinkedList::debug_print_address() {
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur << "," << cur->data << "\t";
    cout << "\n";
}

void LinkedList::debug_print_node(Node *node, bool is_separate) {
    if (is_separate)
        cout << "Sep: ";
    if (node == nullptr) {
        cout << "nullptr\n";
        return;
    }
    cout << node->data << " ";
    if (node->next == nullptr)
        cout << "X ";
    else
        cout << node->next->data << " ";

    if (node == head)
        cout << "head\n";
    else if (node == tail)
        cout << "tail\n";
    else
        cout << "\n";
}

void LinkedList::debug_print_list(string msg) {
    if (msg != "")
        cout << msg << "\n";
    for (int i = 0; i < (int) debug_data.size(); ++i)
        debug_print_node(debug_data[i]);
    cout << "************\n" << flush;
}

string LinkedList::debug_to_string() {
    if (length == 0)
        return "";
    ostringstream oss;
    for (Node *cur = head; cur; cur = cur->next) {
        oss << cur->data;
        if (cur->next)
            oss << " ";
    }
    return oss.str();
}

void LinkedList::debug_verify_data_integrity() {
    if (length == 0) {
        assert(head == nullptr);
        assert(tail == nullptr);
    } else {
        assert(head != nullptr);
        assert(tail != nullptr);
        if (length == 1)
            assert(head == tail);
        else
            assert(head != tail);
        assert(!tail->next);
    }
    int len = 0;
    for (Node *cur = head; cur; cur = cur->next, len++)
        assert(len < 10000); // Consider infinite cycle?
    assert(length == len);
    assert(length == (int) debug_data.size());
}

void LinkedList::print() {
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << "\n";
}

void LinkedList::delete_node(Node *node) {
    debug_remove_node(node);
    --length;
    delete node;
}

void LinkedList::add_node(Node *node) {
    debug_add_node(node);
    ++length;
}

void LinkedList::insert_end(int value) {
    Node *item = new Node(value);
    add_node(item);

    if (!head)
        head = tail = item;
    else
        tail->next = item, tail = item;
}

Node *LinkedList::get_nth(int n) {
    int cnt = 0;
    for (Node *cur = head; cur; cur = cur->next)
        if (++cnt == n)
            return cur;

    return nullptr;
}

// Problem #1: Destructor
LinkedList::~LinkedList() {
    Node *current = head;
    Node *nextNode = nullptr;
    while (current) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

// Problem #2: Insert front
void LinkedList::insert_front(int value) {
    Node *item = new Node(value);
    add_node(item);

    if (!head)
        head = tail = item;
    else {
        item->next = head;
        head = item;
    }
}

// Problem #3: Delete front
void LinkedList::delete_front() {
    if (!head) {
        cout << "List is empty, nothing to delete\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete_node(temp);

    // If the list becomes empty after deletion (it had one node)
    if (!head) {
        tail = nullptr;
    }
}

// Problem #4: Get nth from back
Node *LinkedList::get_nth_back(int n) {
    int positionFront = length - n + 1;
    return get_nth(positionFront);
}

// Problem #5: Is Same list’s data? (with length)
bool LinkedList::is_same(const LinkedList &other) {
    if (length != other.length) {
        return false;
    }

    Node *currentThis = head;
    Node *currentOther = other.head;

    while (currentThis && currentOther) {
        if (currentThis->data != currentOther->data) {
            return false;
        }

        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }

    return true;
}

// Problem #5: Is Same list’s data? (without length)
bool LinkedList::is_same2(const LinkedList &other) {
    Node *currentThis = head;
    Node *currentOther = other.head;

    while (currentThis && currentOther) {
        if (currentThis->data != currentOther->data) {
            return false;
        }

        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }

    return (currentThis == nullptr && currentOther == nullptr);
}

// Problem #6: Linked List without tail/length!
// Test in test.cpp
void LinkedList::print6() {
    Node *current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

void LinkedList::add_element(int value) {
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    length++;
}

Node *LinkedList::get_tail() {
    if (!head) {
        cout << "List is empty, no tail\n";
        return nullptr;
    }

    Node *current = head;
    while (current->next) {
        current = current->next;
    }

    return current;
}

// Problem #1: Delete with key
void LinkedList::delete_node_with_key(int value) {
    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        if (current == tail) {
            tail = prev;
        }

        delete_node(current);
    } else {
        cout << "Node not found in the list\n";
    }
}

// Problem #2: Swap each pair vales
void LinkedList::swap_pairs() {
    Node *current = head;

    while (current != nullptr && current->next != nullptr) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        current = current->next->next;
    }
}

// Problem #3: Reverse list nodes
void LinkedList::reverse() {
    if (length <= 1) {
        return;
    }

    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    head = prev;
    tail = head;
}

// Problem #4: Delete even positions
void LinkedList::delete_even_positions() {
    if (length <= 1) {
        return;
    }

    Node *current = head;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->next != nullptr) {
            Node *next = current->next->next;
            delete_node(current->next);
            current->next = next;
            length--;
        }

        prev = current;
        current = current->next;
    }

    tail = current == nullptr ? prev : current;
}

// Problem #5: Insert to be sorted
void LinkedList::insert_sorted(int value) {
    Node *new_node = new Node(value);

    if (!head || value <= head->data) {
        new_node->next = head;
        head = new_node;
        tail = (!head->next) ? new_node : tail;
    } else {
        Node *current = head;

        while (current->next && current->next->data < value) {
            current = current->next;
        }

        new_node->next = current->next;
        current->next = new_node;
        tail = (!new_node->next) ? new_node : tail;
    }

    length++;
}

// Problem #1: Swap head and tail
void LinkedList::swap_head_tail() {
    if (!head || head == tail) {
        return;
    }

    if (length == 2) {
        swap_pairs();
        return;
    }

    Node *second_last = nullptr;
    Node *current = head;
    while (current->next != nullptr) {
        second_last = current;
        current = current->next;
    }

    current->next = head->next;
    head->next = nullptr;
    second_last->next = head;
    head = current;

    cout << "After swapping head and tail:\n";
    print();
    debug_print_address();
}
