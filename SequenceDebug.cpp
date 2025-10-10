/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    Node* head = new Node("Test");
    head->next = new Node("Test2");
    head->next->next = new Node("Test3");
    head->next->next->next = new Node("Test4");

    while (head != nullptr) {
        cout << head->value << endl;
        if (head->next)
            cout<<"->";

        head = head->next;
    }

    cout << "Your project is ready to go!" << endl;

    return 0;
}