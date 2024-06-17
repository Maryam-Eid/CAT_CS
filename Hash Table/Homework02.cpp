#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

typedef unsigned long long ull;

using namespace std;

// Problem #1: Number of Distinct Substring
int count_unique_substrings(const string &str) {
    unordered_set<ull> unique;
    int n = str.size();

    for (int i = 0; i < n; ++i) {
        ull hash = 0;
        for (int j = i; j < n; ++j) {
            // 257 for ASCII
            hash = hash * 257 + str[j];
            unique.insert(hash);
        }
    }

    return unique.size();
}

// Problem #2: Common substrings
unordered_set<ull> generate_hashes(const string &str) {
    unordered_set<ull> hashes;
    int n = str.size();

    for (int i = 0; i < n; ++i) {
        ull hash = 0;
        for (int j = i; j < n; ++j) {
            // 257 for ASCII
            hash = (hash * 257 + (str[j] - 'a' + 1)) % (ull) 1e9 + 9;
            hashes.insert(hash);
        }
    }

    return hashes;
}

int count_substrings_match(const string &str1, const string &str2) {
    unordered_set hashes1 = generate_hashes(str1);
    unordered_set hashes2 = generate_hashes(str2);

    int common = 0;
    for (int hash: hashes1) {
        if (hashes2.count(hash))
            common++;
    }

    return common;
}

// Problem #3: Unique Anagrams
int count_anagram_substrings(const string &str) {
    unordered_set<string> hashes;
    int n = str.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string sub = str.substr(i, j - i + 1);
            sort(sub.begin(), sub.end());
            hashes.insert(sub);
        }
    }

    return hashes.size();
}

int main() {
    cout << count_anagram_substrings("aaaaa");
}