#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
#include "Cart.h"

using namespace std;

Cart::Cart(const string& currentUsername) {
    username = currentUsername;
    Cartfilename = "cart_" + username + ".csv";

    loadSourceProductList("product.csv", "listing.csv");

    loadCartfromFile();
}

void Cart::loadSourceProductList(const string& Productfile, const string& Filelisting) {
    map <int, string> Nameofproducts;
    ifstream Filep(Productfile);
    if (Filep.is_open()) {
        string line;
        getline(Filep, line);
        while (getline(Filep, line)) {
            stringstream ss(line);
            string field;
            int Idproduct;
            string Nameofproduct;
            getline(ss, field, ',');
            Idproduct = stoi(field);
            getline(ss, Nameofproduct, ',');
            Nameofproducts[Idproduct] = Nameofproduct;
        }
    }
    Filep.close();

    ifstream FileL(Filelisting);
    if (!FileL.is_open()) {
        cerr << "Error: Could not open the list file: " << Filelisting << endl;
        return;
    }
    string line;
    getline(FileL, line);
    while (getline(FileL, line)) {
        stringstream ss(line);
        string field;
        DetailsofProduct p;

        getline(ss, field, ','); p.Idlisting = stoi(field);
        getline(ss, field, ','); p.Idproduct = stoi(field);
        getline(ss, field, ','); p.Nameofseller = stoi(field);
        getline(ss, field, ','); p.price = stoi(field);
        getline(ss, field, ','); p.Stockavailable = stoi(field);

        if (Nameofproducts.count(p.Idproduct)) {
            p.Nameofproduct = Nameofproducts[p.Idproduct];
        } 
        else {
            p.Nameofproduct = "Unknown";
        }
        sourceProductList.push_back(p);
    }
    FileL.close();
}

void Cart::loadCartfromFile() {
    ifstream file(Cartfilename);
    if (!file.is_open()) {
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string Idlisting_str, quantity_str;
        getline(ss, Idlisting_str, ',');
        getline(ss, quantity_str, ',');
    }
    file.close();
}

void Cart::addProductTocart(int Idlisting, int quantity) {
    for (auto& item : items) {
        if (item.product.Idlisting == Idlisting) {
            item.quantity += quantity;
            cout << "Upadated quantity for" << item.product.Nameofproduct << "." << endl;
            return;

        }
    }

    for (const auto& product : sourceProductList) {
        if (product.Idlisting == Idlisting) {
            if (quantity > product.Stockavailable) {
                cout << "Error: Not enough stock for " << product.Nameofproduct << ". Only" << product.Stockavailable << " available." << endl;
                return;
            }
            Itemcart Newitem ={product, quantity};
            items.push_back(Newitem);
            cout <<  "Added " << product.Nameofproduct << " to cart." << endl;
            return;
        }
    }
    cout << "Error: Product with listing ID " << Idlisting << " not found in your cart." << endl;
}

void Cart::deleteProductfromCart(int Idlisting) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->product.Idlisting == Idlisting) {
            cout << "Removed " << it->product.Nameofproduct << " from cart." << endl;
            items.erase(it);
            return;
        }
    }
    cout << "Error: Listing ID " << Idlisting << " not found in your cart." << endl;
}

void Cart::clearCart() {
    items.clear();
    cout << "Your cart has been cleared." << endl; 
}

void Cart::showCartSummary() {
    if (items.empty()) {
        cout << "\nYour shopping cart is empty." << endl;
        return;
    }

    double subtotal = 0.0;
    cout << "\n--- Cart Summary for " << username << " ---" << endl;
    cout << left << setw(12) << "Listing ID" << setw(25) << "Product Name"
         << setw(18) << "Seller" << setw(12) << "Price"
         << setw(10) << "Quantity" << setw(12) << "Total" << endl;
    cout << string(89, '-') << endl;

    for (const auto& item : items) {
        double total = item.product.price * item.quantity;
        subtotal += total;
        cout << left << setw(12) << item.product.Idlisting
             << setw(25) << item.product.Nameofproduct
             << setw(18) << item.product.Nameofseller
             << "$" << fixed << setprecision(2) << setw(11) << item.product.price
             << setw(10) << item.quantity
             << "$" << fixed << setprecision(2) << setw(11) << total << endl;
    }
    cout << string(89, '-') << endl;
    cout << right << setw(77) << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "--- End of Summary ---\n" << endl;
}

void Cart::updateQuantityinCart(int Idlisting, int newQuantity) {
    if (newQuantity <= 0) {
        cout << "Quantity must be positive. To remove an item, use the delete option." << endl;
        return;
    }

    for (auto& item : items) {
        if (item.product.Idlisting == Idlisting) {
            if (newQuantity > item.product.Stockavailable) {
                cout << "Error: Not enough stock. Only " << item.product.Stockavailable << " available." << endl;
                return;
            }
            item.quantity = newQuantity;
            cout << "Updated quantity for " << item.product.Nameofproduct << "to" << newQuantity << "." << endl;
            return;
        }
    }
    cout << "Error: Listing ID " << Idlisting << " not found in your cart." << endl;
}

void Cart::generateCartfile() {
    ofstream file(Cartfilename);
    if (!file.is_open()) {
        cerr << "Error: Could not save cart file for user " << username << "." << endl;
        return;
    }

    file << "listing_ID,quantity" << endl;

    for (const auto& item : items) {
        file << item.product.Idlisting << "," << item.quantity << endl;
    }

    file.close();
    cout << "Cart saved successfully for " << username << "." << endl;
}