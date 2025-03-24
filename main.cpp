/*
    Matthew Winer
    CMPR 131
    March 21 2025
    HW2
*/
#include <iostream>
#include <string>
#include <termcolor/termcolor.hpp>
#include <fstream>
#include "cart.h"
using namespace std;
void displayMenu();
int main() {
    cart cart1;
    int choice;
    string item;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << termcolor::cyan <<"Enter item to add: ";
                getline(cin,item);
                cart1.addItem(item);
                cout << termcolor::green << "Item Added !!\n";
                break;
            case 2:
                cout << termcolor::cyan << "Enter Item to remove: ";
                getline(cin,item);
                if (cart1.removeItem(item)) {
                    cout << termcolor::green << "ITEM REMOVED\n";
                } else {
                    cout << termcolor::red << "Item Not Found\n";
                }
                break;
            case 3:
                cout << termcolor::bright_cyan << "Items In The Cart\n";
                cart1.listItems();
                break;
            case 4:
                cout << termcolor::on_yellow << "Number of items in cart: " << cart1.getNumOfItems() << "\n" << termcolor::reset;
                break;
            case 5:
                cart1.clearCart();
                cout << termcolor::on_bright_red << "CART CLEARED\n" << termcolor::reset;
                break;
            case 6:
                cart1.saveCart();
                break;

            case 7:
                cout << termcolor::bright_cyan << "Cart contents:\n" << termcolor::reset;
                cout << cart1;
                break;

            case 0:
                cout << termcolor::bright_magenta << "Exiting program. Goodbye!\n" << termcolor::reset;
                break;
            default:
                cout << termcolor::red << "Invalid Entry Try again \n" << termcolor::reset;
                break;
        }
    } while (choice !=0);
    return 0;
}
void displayMenu() {
    std::ifstream file("menu.txt");
    if (!file) {
        cerr << termcolor::red << "ERR 03: menu.txt Not Found\n";
        return;
    }
    string line;
    while (getline(file,line)) {
        if (line == "=== Shopping Cart Menu ===") {
            cout << termcolor::bright_cyan << line << termcolor::reset << "\n";
        } else if (line == "Enter Your Choice: ") {
            cout << termcolor::yellow << line << termcolor::reset << "\n";
        } else if (line == "==========================") {
            cout << termcolor::grey << line << termcolor::reset << "\n";
        } else {
            cout << termcolor::green << line << termcolor::reset << "\n";
        }
    }
    file.close();
}


