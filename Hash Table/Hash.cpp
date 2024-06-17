#include "hash.h"
#include <string>

using namespace std;

int Hash::hash_num(int value, int n) {
    // Hashed value in range [0, n-1]
    return value % n;
}

int Hash::hash_string1(const string& str, int n) {
    int sum = 0;
    for (int i = 0; i < (int) str.size(); ++i)
        sum += str[i] - 'a';    // to 0-25 range
    return sum % n;
}

int Hash::hash_string2(const string& str, int n) {
    int sum = 0;
    for (int i = 0; i < (int) str.size(); ++i)
        sum = sum * 26 + str[i] - 'a';    // base 26 number
    cout << sum << "\n";
    return sum % n;
}

// Problem #1: Small, upper and digits
int Hash::hash_string3(const string& str, int n) {
    int sum = 0;
    for (char c: str) {
        if (islower(c)) {
            sum += (c - 'a') % n;
        } else if (isupper(c)) {
            sum += ((c - 'A') + 26) % n;
        } else if (isdigit(c)) {
            sum += ((c - '0') + 52) % n;
        }
    }
    return sum % n;
}

// Problem #2: Folding for hashing
int Hash::hash_folding(const string& str, int n) {
    int len = str.length();
    int sum = 0;
    for (int i = 0; i < len; i += 4) {
        sum += hash_string1(str.substr(i, 4), n);
    }
    return sum % n;
}

// Problem 3: Key based on multiple variables
int Hash::hash(const string &str1, const string &str2, int number) {
    string combined = str1 + str2 + to_string(number);
    return hash_string3(combined, INTERNAL_LIMIT);
}