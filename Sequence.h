#ifndef LINKEDLIST_SEQUENCE_H
#define LINKEDLIST_SEQUENCE_H
#include <stdexcept>
#include <vector>
#include <string>
#include <ostream>
class Node{
public:
    std::string value;
    Node *next;
    Node(std::string value, Node *next = nullptr){
        this->value = value;
        this->next = next;
    }
    std::string getValue(){return this->value;}
    Node * getNext() {return this->next;}
    void setNext(Node *next) {this->next = next;}
};
class LinkedList {
private:
    Node *head;
    public:
    // Constructor
    LinkedList() {
        this->head = nullptr;
    }
    // Destructor
    ~LinkedList() {
        while (this-> head != nullptr) pop();
    }
    // Insertion Operator <<
    friend std::ostream & operator <<(std::ostream & os, const LinkedList & rhs) {
        for (Node *curSequence = rhs.head; curSequence != nullptr; curSequence = curSequence->getNext()) {
           os << curSequence->getValue();
            if (curSequence->getNext() != nullptr) os << " ";
        }

    }

    // Add Links (push)
    void push (std::string value) {
        new Node(value, this->head);
    }
    // Remove Links (pop)
    int pop() {
        int value;
        if (this->head != nullptr) {
        Node* temp = head;
            this->head = this->head->getNext();
            delete temp;
        }else {
            throw std::range_error("List is empty!");
        }

        return value;
    }
    // Find Length
    // Find a value

};









#endif //LINKEDLIST_SEQUENCE_H