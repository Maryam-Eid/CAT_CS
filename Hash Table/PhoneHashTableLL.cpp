#include "PhoneHashTableLL.h"

PhoneHashTableLL::PhoneHashTableLL(int table_size, double limit_load_factor)
        : table_size(table_size), limit_load_factor(limit_load_factor), current_size(0) {
    table = new Node *[table_size];
    for (int i = 0; i < table_size; ++i) {
        table[i] = nullptr;
    }
}

void PhoneHashTableLL::put(PhoneEntry phone) {
    int idx = phone.hash() % table_size;
    Node *newNode = new Node(phone);

    if (table[idx] == nullptr)
        table[idx] = newNode;
    else {
        Node *curr = table[idx];
        Node *prev = nullptr;
        while (curr) {
            if (curr->data.name == phone.name) {
                curr->data.phone_number = phone.phone_number;
                delete newNode;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }
}


void PhoneHashTableLL::print_all() {
    for (int i = 0; i < table_size; ++i) {
        if (table[i]) {
            cout << "Hash " << i << ": ";
            Node* curr = table[i];
            while (curr) {
                curr->data.print();
                curr = curr->next;
            }
            cout << "\n";
        }
    }
}
