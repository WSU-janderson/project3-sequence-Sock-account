#ifndef LINKEDLIST_SEQUENCE_H
#define LINKEDLIST_SEQUENCE_H
#include <vector>
#include <string>
class Sequence{
private:
    int value;
    Sequence *next;
    public:
    Sequence(int value, Sequence *next = nullptr){
        this->value = value;
        this->next = next;
    }
    int getValue(){return this->value;}
    Sequence * getNext() {return this->next;}
    void setNext(Sequence *next) {this->next = next;}
};










#endif //LINKEDLIST_SEQUENCE_H