#ifndef LIST_HPP
#define LIST_HPP
#include<string>
#include<vector>

struct sellerD
{
    int listing_id	, product_id ;	
    std::string seller_name	;
    double price ;
    int  stock_in_hand	,shipping_days	,likes	,sale_percentage ,added_to_cart	, Sold;

};


class listing
{

private:

    const std::string filepath="listings.csv";
    std::vector<sellerD> record;

public:

    void updateCartNum(const int &number);
    void updateLike(const int &number);

    void read_record(int prod_id);
    void print_sell();
    
    void updateScore();

};

#endif