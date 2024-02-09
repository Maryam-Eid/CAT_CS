#include "SLL/SLL.h"
#include <iostream>

int main() {
    // Problem #6: Linked List without tail/length!

    LinkedList myList;

    // Add elements
    myList.add_element(10);
    myList.add_element(8);
    myList.add_element(15);
    myList.add_element(6);

    // Print the list
    cout << "List: ";
    myList.print6();

    // Get the tail
    Node *tail = myList.get_tail();
    cout << "Tail: " << tail->data << "\n";

    myList.left_rotate(1);
    myList.print();
    return 0;
}
