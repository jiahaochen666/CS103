#include "LinkedList.hpp"

struct LinkedList::Entry{
    Value value;
    Entry* next;
};

LinkedList::LinkedList(){
    this->head_ = nullptr;
}

LinkedList::~LinkedList(){
    Entry* current = this->head_;
    while (current != nullptr){
        Entry* next = current->next;
        delete current;
        current = next;
    }
    current = nullptr;
    this->head_ = nullptr;
}

void LinkedList::push_front(const Value &value){
    if (this->head_ == nullptr){
        this->head_ = new Entry {value, nullptr};
    }
    else{
        Entry* entry = new Entry{value, this->head_};
        this->head_ = entry;
    }
}

LinkedList::Iterator LinkedList::begin(){
    return Iterator(this->head_);
}

LinkedList::Iterator LinkedList::end(){
    return Iterator(nullptr);
}

LinkedList::Iterator::Iterator(LinkedList::Entry *value) {
    this->entry_ = value;
}

bool LinkedList::Iterator::operator==(const LinkedList::Iterator &other) {
    return this->entry_ == other.entry_;
}

bool LinkedList::Iterator::operator!=(const LinkedList::Iterator &other) {
    return this->entry_ != other.entry_;
}

LinkedList::Iterator LinkedList::Iterator::operator++() {
    this->entry_ = this->entry_->next;
    return Iterator(this->entry_);
}

LinkedList::Value &LinkedList::Iterator::operator*() {
    return this->entry_->value;
}

LinkedList::Value *LinkedList::Iterator::operator->() {
    return &this->entry_->value;
}
