#include<sstream>
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
#include"listing.h"
#include"product.h"
using namespace std;

void listing::read_record(int prod_id)
{
    fstream fin;
    fin.open(filepath, ios::in);
    
    if (!fin.is_open()) {
        cout << "Error opening listings file!" << endl;
        return;
    }

    // Clear previous records
    record.clear();
    
    string line;
    // Skip header
    getline(fin, line);

    // Read data line by line
    while (getline(fin, line)) {
        if(line.empty()) continue;
        
        stringstream ss(line);
        vector<string> row;
        string cell;
        
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if(row.size() < 10) continue; // Skip invalid rows
        
        try {
            if(stoi(row[1]) == prod_id) {
                sellerD temp;
                temp.listing_id = stoi(row[0]);
                temp.product_id = stoi(row[1]);
                temp.seller_name = row[2];
                temp.price = stoi(row[3]);
                temp.stock_in_hand = stoi(row[4]);
                temp.shipping_days = stoi(row[5]);
                temp.likes = stoi(row[6]);
                temp.sale_percentage = stoi(row[7]);
                temp.added_to_cart = stoi(row[8]);
                temp.Sold = stoi(row[9]);
                record.push_back(temp);
            }
        }
        catch(const exception& e) {
            cout << "Error parsing row: " << line << endl;
            continue;
        }
    }
    fin.close();
}

void listing::print_sell()
{
    if(record.empty()) {
        cout << "No listings found for this product." << endl;
        return;
    }

    for (const auto& item : record) {
        cout << "========== Seller " << item.listing_id << " ==========" << endl;
        cout << "##Note: seller number is system generated. It is not sequential!" << endl;
        cout << left << setw(18) << "Seller Name" << ": " << item.seller_name << endl;
        cout << left << setw(18) << "Price (USD)" << ": $" << fixed << setprecision(2) << item.price << endl;
        cout << left << setw(18) << "Stock in Hand" << ": " << item.stock_in_hand << endl;
        cout << left << setw(18) << "Shipping Days" << ": " << item.shipping_days << " days" << endl;
        cout << left << setw(18) << "Likes" << ": " << item.likes << endl;
        cout << left << setw(18) << "Sale %" << ": " << item.sale_percentage << "%" << endl;
        cout << left << setw(18) << "Added to Cart" << ": " << item.added_to_cart << endl;
        cout << left << setw(18) << "Sold" << ": " << item.Sold << endl;
        cout << "------------------------------" << endl << endl;
    }
}

void listing::updateScore()
{
    for(auto& item : record) {
        double score = (0.4 * item.sale_percentage) 
                    + (0.3 * item.likes) 
                    + (0.2 * item.added_to_cart) 
                    + (0.2 * item.Sold) 
                    - (0.2 * item.price) 
                    - (0.1 * item.stock_in_hand) 
                    - (0.2 * item.shipping_days);
        // Score will be used in future implementations
    }
}

void listing::updateCartNum(const int& number)
{
    // Will be implemented in future to update cart numbers
}

void listing::updateLike(const int& number)
{
    // Will be implemented in future to update likes
}