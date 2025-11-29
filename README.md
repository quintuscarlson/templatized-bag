# Templatized Bag (C++)

## Overview
This project implements a **templatized dynamic array Bag (multiset)** in C++:
- Stores elements of any type using a dynamic array
- Automatically resizes the array as elements are added or removed
- Supports counting, removal, and combination of elements
It showcases dynamic memory management, templates, and operator overloading in C++.

---

## Files
- main.cpp // Driver program demonstrating Bag usage
- bag.h // Bag class declaration 
- bag.cpp // Bag class implementation

---

## Skills Demonstrated 
- **C++ templates** (generic class design)
- **Dynamic memory management** (new, delete, resizing arrays)
- **Operator overloading** (operator<<, operator[], operator+=, operator=)
- **Copy constructor & assignment operator**
- **Insert, erase, and count logic**
- **Handling dynamic array capacity**
- **Deep copying and resource safety**
- **Class design and encapsulation**

---

## Build Instructions
**Compile with a standard C++ compiler:** g++ -std=c++17 main.cpp -o bag

**Run with:** ./bag

---

## Usage
**The program demonstrates:**
- Inserting integers or strings into a Bag
- Counting occurrences of an element
- Removing one or all occurrences of an element
- Combining Bags with +=
- Printing the Bag contents

---

## Example
**Usage example:**    
Initial bag size: 0  
Adding 10 1s to a capacity 0 bag  
b: 1 1 1 1 1 1 1 1 1 1  
b2: 1 1 1 1 1 1 1 1 1 1  
b2.insert(2)  
b2: 1 1 1 1 1 1 1 1 1 1 2  
b: 1 1 1 1 1 1 1 1 1 1  
b = b2  
b: 1 1 1 1 1 1 1 1 1 1 2  

---

## Additional Information
- The Bag automatically doubles capacity when full and halves it when usage falls below 25%
- Supports any type T that can be assigned and printed with <<
- The driver program demonstrates both integer and string Bags

---

## Notes on Originality 
This project was originally based on an academic assignment with a starter skeleton provided by the instructor. All dynamic array logic, Bag functionality, operator overloading, and memory management were implemented by me using that provided structure. This README does not claim exclusive authorship over the original skeleton, only over the work I added.
