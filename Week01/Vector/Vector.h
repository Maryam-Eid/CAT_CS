#include <iostream>

class Vector {
private:
    int *arr{nullptr};
    int size{0};
    int capacity{};

    void expand_capacity();

public:
    Vector(int size);

    ~Vector();

    int get_size();

    int get_front();

    int get_back();

    int get(int idx);

    void set(int idx, int val);

    void print();

    int find(int value);

    void push_back(int value);

    void right_rotate();

    void left_rotate();

    void right_rotate(int times);

    int pop(int idx);

    int find_transposition(int value);
};