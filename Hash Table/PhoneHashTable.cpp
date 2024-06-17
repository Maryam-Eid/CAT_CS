#include "PhoneHashTable.h"

// Problem #4: Rehashing (0)
PhoneHashTable::PhoneHashTable(int table_size, double limit_load_factor)
        : table_size(table_size), limit_load_factor(limit_load_factor), current_size(0) {
    table.resize(table_size);
}


bool PhoneHashTable::get(PhoneEntry &phone) {
    if ((double) (current_size + 1) / table_size > limit_load_factor) {
        rehashing();
    }

    int idx = phone.hash() % table_size;

    for (int i = 0; i < (int) table[idx].size(); ++i) {
        if (table[idx][i].name == phone.name) {
            phone = table[idx][i];
            return true;
        }
    }
    return false;
}

void PhoneHashTable::put(PhoneEntry phone) {
    int idx = phone.hash() % table_size;

    for (int i = 0; i < (int) table[idx].size(); ++i) {
        if (table[idx][i].name == phone.name) {
            table[idx][i] = phone; // exist => update
            return;
        }
    }
    table[idx].push_back(phone);
}

bool PhoneHashTable::remove(PhoneEntry phone) {
    int idx = phone.hash() % table_size;
    for (int i = 0; i < (int) table[idx].size(); ++i) {
        if (table[idx][i].name == phone.name) {
            // Swap with last and remove last in O(1)
            swap(table[idx][i], table[idx].back());
            table[idx].pop_back();
            return true;
        }
    }
    return false;
}

void PhoneHashTable::print_all() {
    for (int hash = 0; hash < table_size; ++hash) {
        if (table[hash].size() == 0)
            continue;

        cout << "Hash " << hash << ": ";
        for (int i = 0; i < (int) table[hash].size(); ++i)
            table[hash][i].print();
        cout << "\n";
    }
}

// Problem #4: Rehashing (1)
void PhoneHashTable::rehashing() {
    table_size *= 2;
    vector<vector<PhoneEntry>> new_table(table_size);

    for (int hash = 0; hash < table_size; ++hash) {
        for (int idx = 0; idx < (int) (table[hash].size()); ++idx) {
            int new_idx = table[hash][idx].hash() % table_size;
            new_table[new_idx].push_back(table[hash][idx]);
        }
    }

    table = new_table;
}
