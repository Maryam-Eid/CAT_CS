#ifndef PHONEHASHTABLELL_H
#define PHONEHASHTABLELL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "hash.h"

using namespace std;

int hash_string(string str, int n) {
    long long nn = n;
    long long sum = 0;
    for (int i = 0; i < (int) str.size(); ++i)
        sum = (sum * 26 + str[i] - 'a') % nn;
    return sum % nn;
}

struct PhoneEntry {
    const static int INTERNAL_LIMIT = 65407;
    string name;            // key
    string phone_number;    // data

    int hash() {
        return hash_string(name, INTERNAL_LIMIT);
    }

    PhoneEntry(string name, string phone_number) :
            name(name), phone_number(phone_number) {
    }

    void print() {
        cout << "(" << name << ", " << phone_number << ")  ";
    }
};

// Problem #5: Array of linked-list
struct Node {
    PhoneEntry data;
    Node *next;

    Node(PhoneEntry data) : data(data), next(nullptr) {}
};


class PhoneHashTableLL {
private:
    int table_size;
    double limit_load_factor;
    Node **table;
    int current_size;

    void rehashing();

public:
    PhoneHashTableLL(int table_size = 10, double limit_load_factor = 0.75);

    void put(PhoneEntry phone);

    void print_all();

};

#endif
