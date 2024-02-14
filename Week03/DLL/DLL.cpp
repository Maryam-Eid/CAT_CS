#include "DLL.h"
#include <sstream>
#include <cassert>

using namespace std;

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

LinkedList::LinkedList() {
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

    if (node->prev == nullptr)
        cout << "X\t";
    else
        cout << node->prev->data << "\t";

    cout << " <= [" << node->data << "]\t => \t";

    if (node->next == nullptr)
        cout << "X\t";
    else
        cout << node->next->data << "\t";

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
        assert(!head->prev);
        assert(!tail->next);
    }
    int len = 0;
    for (Node *cur = head; cur; cur = cur->next, len++) {
        if (len == length - 1)    // make sure we end at tail
            assert(cur == tail);
    }

    assert(length == len);
    assert(length == (int) debug_data.size());

    len = 0;
    for (Node *cur = tail; cur; cur = cur->prev, len++) {
        if (len == length - 1)    // make sure we end at head
            assert(cur == head);
    }
    cout << "\n";
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

void LinkedList::print_reversed() {
    for (Node *cur = tail; cur; cur = cur->prev)
        cout << cur->data << " ";
    cout << "\n";
}

// Problem #1: Delete all nodes with key
void LinkedList::delete_all_nodes_with_key(int value) {
    if (!head) return;
    Node *cur = head;

    while (cur) {
        if (cur->data == value) {
            if (cur == head) {
                head = cur->next;
                if (head) head->prev = nullptr;
            } else {
                cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
            }
            --length;
        }

        cur = cur->next;
    }
}

// Problem #2: Delete even positions
void LinkedList::delete_even_positions() {
    Node *cur = head;

    while (cur && cur->next) {
        Node *evenNode = cur->next;

        cur->next = evenNode->next;

        if (cur->next) {
            cur->next->prev = cur;
        }

        delete evenNode;

        cur = cur->next;

        --length;
    }

}

// Problem #3: Delete odd positions
void LinkedList::delete_odd_positions() {
    Node *cur = head;

    while (cur) {
        Node *oddNode = cur;
        cur = cur->next;

        if (cur) {
            cur->prev = oddNode->prev;

            if (oddNode->prev) {
                oddNode->prev->next = cur;
            } else {
                head = cur;
            }

            delete oddNode;

            --length;
        }
    }
}


// Problem #4: Is Palindrome
bool LinkedList::is_palindrome() {
    if (length <= 1) return true;

    Node *left = head;
    Node *right = tail;

    while (left != right) {
        if (left->data != right->data) return false;
        if (left->next == right) break;

        left = left->next;
        right = right->prev;
    }
    return true;
}

// Problem #1: Find the middle (with prev)
Node *LinkedList::find_middle() {
    if (!head) return head;

    Node *middle = head;
    Node *end = tail;

    while (end && end->prev && middle != end->prev) {
        middle = middle->next;
        end = end->prev;
    }


    return middle;
}

// Problem #1: Find the middle (without prev)
Node *LinkedList::find_middle2() {
    if (!head) return head;

    Node *middle = head;
    Node *end = head;

    while (end && end->next) {
        middle = middle->next;
        end = end->next->next;
    }

    return middle;
}

// Problem #2: Swap forward with backward (utilizing the length)
void LinkedList::swapForwardWithBackward(int k) {
    if (k <= 0 || k > length || k == length - k + 1) {
        cout << "Invalid value of k for swapping." << endl;
        return;
    }

    Node *currentForward = head, *prevForward = nullptr;
    for (int i = 1; i < k; i++) {
        prevForward = currentForward;
        currentForward = currentForward->next;
    }

    Node *currentBackward = head, *prevBackward = nullptr;
    for (int i = 1; i < length - k + 1; i++) {
        prevBackward = currentBackward;
        currentBackward = currentBackward->next;
    }

    if (prevForward) {
        prevForward->next = currentBackward;
    } else {
        head = currentBackward;
    }

    if (prevBackward) {
        prevBackward->next = currentForward;
    } else {
        head = currentForward;
    }

    Node *temp = currentForward->next;
    currentForward->next = currentBackward->next;
    currentBackward->next = temp;
}

// Problem #2: Swap forward with backward (without utilizing the length)
void LinkedList::swapForwardWithBackward2(int k) {
    if (k <= 0) {
        cout << "Invalid value of k for swapping." << endl;
        return;
    }

    Node *currentForward = head, *prevForward = nullptr;
    for (int i = 1; i < k; i++) {
        if (!currentForward) {
            cout << "Invalid value of k for swapping." << endl;
            return;
        }
        prevForward = currentForward;
        currentForward = currentForward->next;
    }

    Node *currentBackward = head, *prevBackward = nullptr;
    Node *temp = head;
    for (int i = 0; i < k - 1; i++) {
        temp = temp->next;
    }

    while (temp) {
        prevBackward = currentBackward;
        currentBackward = currentBackward->next;
        temp = temp->next;
    }

    if (prevForward) {
        prevForward->next = currentBackward;
    } else {
        head = currentBackward;
    }

    if (prevBackward) {
        prevBackward->next = currentForward;
    } else {
        head = currentForward;
    }

    temp = currentForward->next;
    currentForward->next = currentBackward->next;
    currentBackward->next = temp;
}


// Problem #3: Reverse list nodes
void LinkedList::reverse() {
    Node *current = head;
    Node *prev = nullptr;
    Node *next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Problem #4: Merge lists
void LinkedList::merge_2sorted_lists(LinkedList &other) {
    Node *mergedHead = nullptr;
    Node *mergedTail = nullptr;
    Node *current1 = head;
    Node *current2 = other.head;
    int mergedLength = 0;


    while (current1 && current2) {
        Node *smallerNode = nullptr;

        if (current1->data < current2->data) {
            smallerNode = new Node(current1->data);
            current1 = current1->next;
        } else {
            smallerNode = new Node(current2->data);
            current2 = current2->next;
        }

        if (!mergedHead) {
            mergedHead = smallerNode;
            mergedTail = smallerNode;
        } else {
            mergedTail->next = smallerNode;
            mergedTail = smallerNode;
        }

        mergedLength++;
    }

    while (current1) {
        Node *remainingNode = new Node(current1->data);
        mergedTail->next = remainingNode;
        mergedTail = remainingNode;
        current1 = current1->next;
        mergedLength++;
    }

    while (current2) {
        Node *remainingNode = new Node(current2->data);
        mergedTail->next = remainingNode;
        mergedTail = remainingNode;
        current2 = current2->next;
        mergedLength++;
    }

    head = mergedHead;
    tail = mergedTail;
    length = mergedLength;
}

