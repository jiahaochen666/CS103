#include "HashMap.hpp"

HashMap::HashMap() {
    this->initialize_storage(7);
}

HashMap::~HashMap() {
    delete[] this->buckets_;
}

HashMap::Value &HashMap::operator[](const HashMap::Key &key) {
    return this->insert(std::pair<const Key, Value>(key, 0)).first->second;
}

void HashMap::initialize_storage(HashMap::Size buckets_size) {
    this->size_ = 0;
    this->buckets_size_ = buckets_size;
    this->buckets_ = new LinkedList[this->buckets_size_ + 1];
    this->buckets_[this->buckets_size_].push_front({"end", 0});
}

HashMap::Iterator::Iterator(LinkedList *bucket, LinkedList::Iterator entry) {
    while (bucket->begin() == bucket->end()) {
        bucket++;
        entry = bucket->begin();

    }
    this->bucket_ = bucket;
    this->entry_ = entry;
}

HashMap::Iterator HashMap::begin() {
    return Iterator(&this->buckets_[0], this->buckets_[0].begin());
}

HashMap::Iterator HashMap::end() {
    return Iterator(&this->buckets_[this->buckets_size_], this->buckets_[this->buckets_size_].begin());
}

bool HashMap::Iterator::operator==(const HashMap::Iterator &other) {
    return this->bucket_ == other.bucket_ && this->entry_ == other.entry_;
}

bool HashMap::Iterator::operator!=(const HashMap::Iterator &other) {
    return this->bucket_ != other.bucket_ || this->entry_ != other.entry_;
}

HashMap::Iterator &HashMap::Iterator::operator++() {
    ++this->entry_;
    if (this->entry_ == this->bucket_->end()) {
        do {
            this->bucket_++;
            this->entry_ = this->bucket_->begin();
        } while (this->bucket_->begin() == this->bucket_->end());
    }
    return *this;
}

HashMap::Pair &HashMap::Iterator::operator*() {
    return *(this->entry_);
}

HashMap::Pair *HashMap::Iterator::operator->() {
    return &*this->entry_;
}


LinkedList &HashMap::get_bucket(const HashMap::Key &key) {
    unsigned long long prime = 1099511628211;
    unsigned long long hash = 14695981039346656037ull;
    int key_length = key.length();
    for (int i = 0; i < key_length; i++) {
        hash *= prime;
        hash ^= key[i];
    }
    return this->buckets_[hash % this->buckets_size_];
}

std::pair<HashMap::Iterator, bool> HashMap::insert(const HashMap::Pair &pair) {
    Iterator iter = this->find(pair.first);
    if (iter == this->end()) {
        LinkedList *link = &this->get_bucket(pair.first);
        link->push_front(pair);
        this->size_++;
        if (this->size_ > this->buckets_size_ * 2) {
            Size new_bucket_size_ = this->buckets_size_ * 2;
            this->size_ = 0;
            LinkedList *new_bucket_ = new LinkedList[new_bucket_size_ + 1];
            new_bucket_[new_bucket_size_].push_front({"end", 0});
            for (unsigned int i = 0; i < this->buckets_size_; i++) {
                LinkedList::Iterator old_iter_ = this->buckets_[i].begin();
                while (old_iter_ != this->buckets_[i].end()) {
                    unsigned long long hash = 14695981039346656037ull;
                    for (unsigned int j = 0; j < old_iter_->first.length(); j++) {
                        hash *= 1099511628211;
                        hash ^= old_iter_->first[j];
                    }
                    hash = hash % (new_bucket_size_);
                    new_bucket_[hash].push_front(LinkedList::Value(old_iter_->first, old_iter_->second));
                    this->size_++;
                    ++old_iter_;
                }
            }
            delete[] this->buckets_;
            this->buckets_ = new_bucket_;
            this->buckets_size_ = new_bucket_size_;
            iter = this->find(pair.first);
            return std::pair<HashMap::Iterator, bool>(iter, true);
        }
        return std::pair<HashMap::Iterator, bool>(Iterator(link, link->begin()), true);
    } else {
        return std::pair<HashMap::Iterator, bool>(iter, false);
    }
}

HashMap::Iterator HashMap::find(const HashMap::Key &key) {
    LinkedList *link = &this->get_bucket(key);
    LinkedList::Iterator iter = link->begin();
    while (iter != link->end()) {
        if (iter->first == key)
            return Iterator(link, iter);
        ++iter;
    }
    return this->end();
}
