//
// Created by mwiner on 3/23/25.
//

#ifndef HW2_CART_H
#define HW2_CART_H
#include <iostream>
#include <string>

class cart {
private:
    std::string *items;
    int capacity;
    int numOfItems;

    void resize();
public:
    cart();
    ~cart();

    void addItem(const std::string& name);
    bool removeItem(const std::string& name);
    void listItems() const;
    int getNumOfItems() const;
    void clearCart();
    void saveCart(const std::string& filename = "cart_output.txt")const;
    cart(const cart& other);
    cart& operator=(const cart& other);
    friend std::ostream& operator<<(std::ostream& out,const cart& cart);
};


#endif //HW2_CART_H
