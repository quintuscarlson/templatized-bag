// Bag class interface file
#ifndef BAG_H
#define BAG_H

#include <iostream>
using std::ostream;

template <typename T>
class Bag {
public:
    // Constructors, destructor, assignment operator
    Bag();                     // default constructor
    Bag(const Bag<T>& other);  // copy constructor
    ~Bag();                    // destructor
    Bag<T>& operator=(const Bag<T>& rhs);

    // Accessors
    size_t size() const { return size_; }   // number of elements
    size_t cap() const { return cap_; }     // allocated capacity
    T operator[](size_t i) const { return data_[i]; }

    // Mutators
    void insert(T val);                   // add element to bag
    size_t count(T val) const;            // count occurrences of val
    bool erase_one(T val);                // erase first occurrence of val
    size_t erase(T val);                  // erase all occurrences of val
    void operator+=(const Bag<T>& rhs);   // add elements from another Bag

private:
    T* data_;       // dynamic array
    size_t size_;   // current number of elements
    size_t cap_;    // allocated capacity

    // INVARIANTS:
    // - data_[0] ... data_[size_-1] contain valid elements
    // - 0.25*cap_ < size_ <= cap_
};

template <typename T>
ostream& operator<<(ostream& out, const Bag<T>& a);

#endif 
