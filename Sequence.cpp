#include "Sequence.h"
#include <exception>
#include <iostream>


//constructor
// Creates an empty sequence (sz == 0) or a sequence of sz items
// indexed from 0 ... (sz - 1).
Sequence::Sequence(size_t sz) {
    this->sz = 0;
    head = nullptr;
    tail = nullptr;
    for (int i = 0; i < sz ; i++) {
        push_back("0");
    }
}
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence& s) {
    sz = 0;
    head = nullptr;
    tail = nullptr;
    for (SequenceNode *current = s.head; current != nullptr; current = current->next) {
        push_back(current->item);
    }
}
// Destroys all items in the sequence and release the memory
// associated with the sequence
Sequence::~Sequence() {
    for (int i = 0; i < sz; i++) {
        SequenceNode *temp_p = tail;
        tail = tail->prev;
        delete temp_p;
    }
}
// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
Sequence& Sequence::operator=(const Sequence& s) {
    for (int i = 0; i < sz; i++) {
        SequenceNode *temp_p = tail;
        tail = tail->prev;
        delete temp_p;
    }
    sz = 0;
    head = nullptr;
    tail = nullptr;
    for (SequenceNode *current = s.head; current != nullptr; current = current->next) {
        push_back(current->item);
    }
    return *this;
}
// The position satisfies ( position >= 0 && position <= last_index() ).
// The return value is a reference to the item at index position in the
// sequence. Throws an exception if the position is outside the bounds
// of the sequence
std::string& Sequence::operator[](size_t position) {
    if (position >= sz) {
        throw std::exception();
    }
    SequenceNode *current = head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->item;
}
// The value of item is append to the sequence.
void Sequence::push_back(std::string item) {
    SequenceNode *newtail = new SequenceNode(item);
    newtail->next = nullptr;
    newtail->prev = tail;
    tail->next = newtail;
    tail = newtail;
    sz++;

}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back() {
    if (sz == 0) {
        throw std::exception();
    }
    SequenceNode *prevt = tail->prev;
    if (prevt == nullptr) {
        delete tail;
        tail = nullptr;
        head = nullptr;
        sz = 0;
        return;
    }
    prevt->next = nullptr;
    delete tail;
    tail = prevt;
    sz--;
}
// The position satisfies ( position >= 0 && position <= last_index() ). The
// value of item is inserted at position and the size of sequence is increased
// by one. Throws an exceptionif the position is outside the bounds of the
// sequence
void Sequence::insert(size_t position, std::string item) {

    if (position < sz ) {
        throw std::exception();
    }
    SequenceNode *newN = new SequenceNode(item);

    if (position == 0) {
        newN->next = head;
        head->prev = newN;
        newN->prev = nullptr;
        head = newN;
        sz++;
        return;
    }
    if (position == sz) {
        newN->next = tail;
        tail->next = newN;
        newN->next = nullptr;
        tail = newN;
        sz++;
        return;
    }
    SequenceNode *current = head;

    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    newN->prev = current->prev;
    newN->next = current;
    current->prev = newN;
    newN->prev->next = newN;
    sz++;
}
// Returns the first element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::front() const {
    SequenceNode *temp = new SequenceNode;
    temp->item = head->item;
    if (temp->item == "") {
        throw std::exception();
    }
    return temp->item;

}
// Return the last element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::back() const {
    SequenceNode *temp = new SequenceNode;
    temp->item =tail->item;
    if (temp->item == "") {
        throw std::exception();
    }
    return temp->item;
}
// Return true if the sequence has no elements, otherwise false.
bool Sequence::empty() const {
    if (head->item == "" && head->next == tail && tail->item == "") {
        return true;
    }
    else {
        return false;
    }
}
// Return the number of elements in the sequence.
size_t Sequence::size() const {
    int count;
    SequenceNode *temp = new SequenceNode;
    for (int i = 0; i < sz; i++) {
        temp->item = head->item;
        if (temp->item != "") {
            count++;
        }
        temp = head->next;
        head->next = temp->next;



    }
}
// All items in the sequence are deleted and the memory associated with the
// sequence is released, resetting the sequence to an empty state that can have
// items re-inserted.
void Sequence::clear() {
    //SequenceNode *temp = new SequenceNode;

    for (int i = 0; i < sz; i++) {
        push_back("");
    }

}
// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position) {
 if (position >= sz) {
     throw std::exception();
 }
    if (position < sz && position >= 0) {

    }
}
// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count) {

}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
std::ostream& operator<<(std::ostream& os, const Sequence& s) {

}