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
    
};