#include "Vector.h"

using namespace std;

int main() {
    Vector v(6);
    for (int i = 0; i < 6; ++i)
        v.set(i, i);

    cout << "Initial Vector: ";
    v.print();

    cout << "Right Rotate: ";
    v.right_rotate();
    v.print();

    cout << "Right Rotate 5 Times: ";
    v.right_rotate(5);
    v.print();

    cout << "Pop 3rd Index: " << v.pop(3) << "\n";
    cout << "Vector After Popping: ";
    v.print();

    cout << "Search for 1 at Index: " << (v.find_transposition(1) + 1) << "\n";
    cout << "Vector After Searching: ";
    v.print();

    return 0;
}