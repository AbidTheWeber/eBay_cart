#ifndef CART_H
#define CART_H

#include <string>
#include <vector>

using namespace std;

struct DetailsofProduct 
{
    int Idlisting;
    int Idproduct;
    string Nameofproduct;
    string Nameofseller;
    double price;
    int Stockavailable;
};

struct Itemcart 
{
    DetailsofProduct product;
    int quantity;
};

class Cart 
{
private:
    string username;
    string Cartfilename;
    vector<Itemcart> items;
    vector<DetailsofProduct> sourceProductList;

    void loadSourceProductList(const string& Productflie, const string& Filelisting);

    void loadCartfromFile();

public: 
    Cart(const string& currentUsername);

    void addProductTocart (int Idlisting, int quantity);

    void deleteProductfromCart (int Idlisting);
    
    
};


#endif
