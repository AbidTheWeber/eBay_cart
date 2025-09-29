#ifndef SEARCH_HPP
#define SEARCH_HPP
#include<vector>


class product;
class listing;
class Cart;

class search
{

private:

const std::string filepath="products.csv";
void showoption();
product* search_result = nullptr;
listing* marketplace = nullptr;
Cart* user_cart=nullptr;
void addCart();


public:

void searchOption();

 void getProduct(product* obj)
    {
       search_result = obj;
    }
 void getMarket(listing* obj)
    {
       marketplace = obj;
    }
void getCart(Cart* obj)
   {
      user_cart=obj;
   }

};

#endif