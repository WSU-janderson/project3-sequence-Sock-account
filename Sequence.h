#ifndef LINKEDLIST_SEQUENCE_H
#define LINKEDLIST_SEQUENCE_H
#include <stdexcept>
#include <vector>
#include <string>
#include <ostream>
class Sequence{
private:
    std::string value;
    Sequence *next;
    public:
    Sequence(std::string value, Sequence *next = nullptr){
        this->value = value;
        this->next = next;
    }
    std::string getValue(){return this->value;}
    Sequence * getNext() {return this->next;}
    void setNext(Sequence *next) {this->next = next;}
};
class LinkedList {
private:
    Sequence *head;
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
    friend std::ostream & operator<<(std::ostream & os, const LinkedList & rhs) {
        for (Sequence *curSequence = rhs.head; curSequence != nullptr; curSequence = curSequence->getNext()) {
           os << curSequence->getValue();
            if (curSequence->getNext() != nullptr) os << " ";
        }

    }

    // Add Links (push)
    void push (std::string value) {
        new Sequence(value, this->head);
    }
    // Remove Links (pop)
    int pop() {
        int value;
        if (this->head != nullptr) {
        Sequence* temp = head;
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