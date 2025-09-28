#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"listing.h"
#include"product.h"
using namespace std;


void listing::updateScore()
{
    int score;
    /*score= (0.4 * Sale_Percentage) 
    + (0.3 * Likes) 
    + (0.2 * Added_to_Cart) 
    + (0.2 * Sold) 
    - (0.2 * Price) 
    - (0.1 * Stock_in_Hand) 
    - (0.2 * Shipping_Days)*/
    //in future to update score / rating of the product based on business logic.

} 

void updateCartNum(const int &number)
{
    //will be in future to update (number of time added to cart) of a product in real time.
}

void updateLike(const int &number)
{
//will be implemented in future to update like of a product in real time.
}


void listing::read_record(int prod_id)
{
    // File pointer
    fstream fin;

    // Open an existing file
    fin.open(filepath, ios::in);


    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, temp;

     // Skip the header row
    getline(fin, line);

    while (fin >> temp)
    {
        int count=0,prod_num;
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        
        // convert string to integer 
        prod_num = stoi(row[1]);

        if(prod_id == prod_num)
        {
            sellerD temp;
            temp.listing_id=stoi(row[0]);
            temp.product_id=stoi(row[1]);
            temp.seller_name=row[2];
            temp.price=stod(row[3]);
            temp.stock_in_hand=stoi(row[4]);
            temp.shipping_days=stoi(row[5]);
            temp.likes=stoi(row[6]);
            temp.sale_percentage=stoi(row[7]);
            temp.added_to_cart=stoi(row[8]);
            temp.Sold=stoi(row[9]);

         record.push_back(temp);   
        }

    }
    fin.close();
}


void listing::print_sell()
{
    // Display seller-specific product records
for (int i = 0; i < record.size(); i++) {
    cout << "========== Seller " << record[i].listing_id << " ==========" << endl;
    cout<<"##Note: seller number is system generated. It is not sequential!"<<endl;
    cout << left << setw(18) << "Seller Name"     << ": " << record[i].seller_name << endl;
    cout << left << setw(18) << "Price (USD)"     << ": $" << record[i].price << endl;
    cout << left << setw(18) << "Stock in Hand"   << ": " << record[i].stock_in_hand << endl;
    cout << left << setw(18) << "Shipping Days"   << ": " << record[i].shipping_days << " days" << endl;
    cout << left << setw(18) << "Likes"           << ": " << record[i].likes << endl;
    cout << left << setw(18) << "Sale %"          << ": " << record[i].sale_percentage << "%" << endl;
    cout << left << setw(18) << "Added to Cart"   << ": " << record[i].added_to_cart << endl;
    cout << left << setw(18) << "Sold"            << ": " << record[i].Sold << endl;
    cout << "------------------------------" << endl << endl;
    }
}