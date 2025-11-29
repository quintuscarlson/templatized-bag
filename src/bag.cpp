// implementation file for Bag class
#include "bag.h"
#include <iostream>
using std::cout;

// Default constructor
template <typename T>
Bag<T>::Bag() : data_(nullptr), size_(0), cap_(0) {}

// Copy constructor
template <typename T>
Bag<T>::Bag(const Bag<T>& other)
    : size_(other.size_), cap_(other.cap_) {
    data_ = new T[cap_];
    for (size_t i = 0; i < size_; i++)
        data_[i] = other.data_[i];
}

// Destructor
template <typename T>
Bag<T>::~Bag() {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    cap_ = 0;
}

// Assignment operator
template <typename T>
Bag<T>& Bag<T>::operator=(const Bag<T>& rhs) {
    if (&rhs == this) return *this;  // self-assignment check

    delete[] data_;
    size_ = rhs.size_;
    cap_ = rhs.cap_;
    if (cap_ > 0) {
        data_ = new T[cap_];
        for (size_t i = 0; i < size_; i++)
            data_[i] = rhs.data_[i];
    } else {
        data_ = nullptr;
    }

    return *this;
}

// Insert element
template <typename T>
void Bag<T>::insert(T val) {
    if (size_ >= cap_) {
        cap_ = (cap_ == 0) ? 1 : cap_ * 2;
        T* temp = new T[cap_];
        for (size_t i = 0; i < size_; i++)
            temp[i] = data_[i];
        delete[] data_;
        data_ = temp;
    }
    data_[size_++] = val;
}

// Count occurrences of val
template <typename T>
size_t Bag<T>::count(T val) const {
    size_t cnt = 0;
    for (size_t i = 0; i < size_; i++)
        if (data_[i] == val)
            cnt++;
    return cnt;
}

// Erase first occurrence of val
template <typename T>
bool Bag<T>::erase_one(T val) {
    for (size_t i = 0; i < size_; i++) {
        if (data_[i] == val) {
            // shift remaining elements left
            for (size_t j = i; j < size_ - 1; j++)
                data_[j] = data_[j + 1];
            size_--;

            // shrink capacity if necessary
            if (size_ <= cap_ / 4 && cap_ > 1) {
                cap_ /= 2;
                T* temp = new T[cap_];
                for (size_t k = 0; k < size_; k++)
                    temp[k] = data_[k];
                delete[] data_;
                data_ = temp;
            }

            return true;
        }
    }
    return false;
}

// Erase all occurrences of val
template <typename T>
size_t Bag<T>::erase(T val) {
    size_t removed = 0;
    while (erase_one(val)) removed++;
    return removed;
}

// Add elements from another bag
template <typename T>
void Bag<T>::operator+=(const Bag<T>& rhs) {
    while (cap_ < size_ + rhs.size_) {
        cap_ = (cap_ == 0) ? 1 : cap_ * 2;
    }

    T* temp = new T[cap_];
    for (size_t i = 0; i < size_; i++)
        temp[i] = data_[i];

    for (size_t i = 0; i < rhs.size_; i++)
        temp[size_ + i] = rhs[i];

    size_ += rhs.size_;

    delete[] data_;
    data_ = temp;
}

// Overloaded << for printing Bag
template <typename T>
ostream& operator<<(ostream& out, const Bag<T>& a) {
    for (size_t i = 0; i < a.size(); i++)
        out << a[i] << " ";
    return out;
}
