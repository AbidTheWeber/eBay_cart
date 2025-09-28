#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include<string>
#include<vector>

struct productD
{
    int id;
    string name;
    string brand;
    string category;
    int warranty_year;
};

class product
{

private:

const std::string filepath="products.csv";
vector<productD> Display;
int read_record(const string &search_term , int search_indiactor);

public:

int getIDname(const string &name);
int getIDbrand(const string &brand);
int getIDcategory(const string &category);
void printProd(int prod_id);

};

#endif