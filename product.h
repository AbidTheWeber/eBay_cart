#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include<string>
#include<vector>

struct productD
{
    int id;
    std::string name;
    std::string brand;
    std::string category;
    int warranty_year;
};

std::string convertToLower(std::string str);

class product
{

private:

    const std::string filepath="products.csv";
    std::vector<productD> Display;
    int read_record(const std::string &search_term , int search_indiactor);

public:

int getIDname(const std::string &name);
int getIDbrand(const std::string &brand);
int getIDcategory(const std::string &category);
void printProd(int prod_id);

};

#endif