//
// Created by mwiner on 3/23/25.
//

#include "cart.h"
#include <fstream>

cart::cart() {
    capacity = 5;
    numOfItems = 0;
    items = new std::string[capacity];
}

cart::~cart() {
    delete [] items;
}

cart::cart(const cart& other) {
    capacity = other.capacity;
    numOfItems = other.numOfItems;
    items = new std::string[capacity];
    for (int i = 0; i < numOfItems; ++i) {
        items[i] = other.items[i];
    }
}
// ASSIGNMENT OPPERATOR
cart& cart::operator=(const cart &other) {
    if (this!=&other) {
        delete [] items;
        capacity = other.capacity;
        numOfItems = other.numOfItems;
        items = new std::string[capacity];
        for (int i = 0;i<numOfItems;++i) {
            items[i] = other.items[i];
        }
    }
    return *this;
}

//Resize function
void cart::resize() {
    int newCapacity = capacity * 2;
    std::string* temp = new(std::nothrow) std::string[newCapacity];
    if (!temp) {
        std::cerr << "ERROR 01: Mem Alloc Failed during resize\n";
        return;
    }
    for (int i = 0; i < numOfItems;++i) {
        temp[i] = items[i];
    }
    delete[] items;
    items = temp;
    capacity = newCapacity;
}

// add item to cart
void cart::addItem(const std::string &name) {
    if (numOfItems >= capacity / 2) {
        resize();
    }
    items[numOfItems++] = name;
}

bool cart::removeItem(const std::string &name) {
    for (int i = 0; i < numOfItems;++i) {
        if (items[i] == name) {
            for (int j = i; j<numOfItems-1;++j) {
                items[j] = items[j+1];
            }
            numOfItems--;
            return true;
        }
    }
    std::cout << "ITEM \""<<name<<"\"Not Found In Cart.\n";
    return false;
}

void cart::listItems() const {
    if (numOfItems == 0) {
        std::cout << "Cart Is Empty\n";
    } else {
        for (int i = 0; i < numOfItems; ++i) {
            std::cout << i + 1 << ". " << items[i] << "\n";
        }
    }
}

int cart::getNumOfItems() const {
    return numOfItems;
}
void cart::clearCart() {
    numOfItems = 0;
    std::cout << "Cart Has Been Cleared\n";
}
void cart::saveCart(const std::string &filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "ERR 02: Unable to open file for saving cart \n";
        return;
    }
    for (int i = 0; i < numOfItems; ++i) {
        outFile << items[i] << "\n";
    }
    outFile.close();
    std::cout << "Cart Saved to " << filename << "\n";
}

//Overload Insertion Operator
std::ostream& operator<<(std::ostream& out, const cart& cart) {
    if (cart.numOfItems == 0) {
        out << "CART IS EMPTY.\n";
    } else {
        for (int i = 0; i < cart.numOfItems;++i) {
            out << i + 1 << ". " << cart.items[i] << "\n";
        }
    }
    return out;
}