#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>

using namespace std;


class Hash {
public:
    static const int INTERNAL_LIMIT = 2147483647;

    int hash_num(int value, int n = 139);

    int hash_string1(const string &str, int n);

    int hash_string2(const string &str, int n);

    int hash_string3(const string &str, int n);

    int hash_folding(const string &str, int n);

    int hash(const string &str1, const string &str2, int number);
};

#endif
