#include "Vector.h"
#include <cassert>

using namespace std;

void Vector::expand_capacity() {
    // Double the actual array size
    capacity *= 2;
    cout << "Expand capacity to " << capacity << "\n";
    int *arr2 = new int[capacity]{};
    for (int i = 0; i < size; ++i)
        arr2[i] = arr[i];    // copy data

    swap(arr, arr2);
    delete[] arr2;
}

Vector::Vector(int size) :
        size(size) {
    if (size < 0)
        size = 1;
    capacity = size + 10;
    // The actual size array will
    // be bigger than needed
    arr = new int[capacity]{};
}

Vector::~Vector() {
    delete[] arr;
    arr = nullptr;
}

int Vector::get_size() {
    return size;
}

int Vector::get(int idx) {
    assert(0 <= idx && idx < size);
    return arr[idx];
}

void Vector::set(int idx, int val) {
    assert(0 <= idx && idx < size);
    arr[idx] = val;
}

void Vector::print() {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int Vector::find(int value) {
    for (int i = 0; i < size; ++i)
        if (arr[i] == value)
            return i;
    return -1;    // -1 for NOT found
}

int Vector::get_front() {
    return arr[0];
}

int Vector::get_back() {
    return arr[size - 1];
}

void Vector::push_back(int value) {
    // we can't add any more
    if (size == capacity)
        expand_capacity();
    arr[size++] = value;
}

void Vector::right_rotate() {

    int last_element{arr[size - 1]};

    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = last_element;
}

void Vector::left_rotate() {

    int first_element{arr[0]};

    for (int i = 0; i <= size - 2; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first_element;
}

void Vector::right_rotate(int times) {

    times %= size;

    while (times--)
        right_rotate();

}

int Vector::pop(int idx) {
    if (idx >= size || idx < 0) {
        cout << "Error: Index out of bounds in pop function\n";
        return -1;
    }

    int element = arr[idx];

    for (int i = idx; i <= size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    size--;
    return element;
}

int Vector::find_transposition(int value) {

    for (int i = 0; i <= size - 1; ++i) {
        if (arr[i] == value){
            if (i == 0)
                return i;

            else {
                swap(arr[i], arr[i - 1]);
                return i - 1;
            }
        }
    }
    return -1;
}


