#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
#include"product.h"
using namespace std;



int product::getIDname(const string &name)
{
    int number;
    number=read_record(name,0);
    return number;
}


int product::getIDbrand(const string &brand)
{
     int number;
    number=read_record(brand,1);
    return number;

}


int product::getIDcategory(const string &category)
{
     int number;
    number=read_record(category,2);
    return number;

}

string convertToLower(string str) {
    for(char& c : str) {
        c = tolower(c);
    }
    return str;
}




int product::read_record(const string &search_term, int search_indiactor)
{
    fstream fin;
    fin.open(filepath, ios::in);
    
    if (!fin.is_open()) {
        cout << "Error opening file!" << endl;
        return 0;
    }

    string line;
    // Skip header
    getline(fin, line);

    // Convert search term to lowercase for case-insensitive search
    string search_lower = convertToLower(search_term);

    // Read file line by line
    while (getline(fin, line)) {
        stringstream ss(line);
        vector<string> row;
        string cell;

        // Parse CSV line
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        // Skip invalid rows
        if (row.size() < 5) continue;

        try {
            int prod_id = stoi(row[0]);

            // For displaying product details
            if (search_indiactor == 4) {
                if (search_term == row[0]) {
                    Display.resize(1);
                    Display[0].id = prod_id;
                    Display[0].name = row[1];
                    Display[0].brand = row[2];
                    Display[0].category = row[3];
                    Display[0].warranty_year = stoi(row[4]);
                    fin.close();
                    return 0;
                }
            }
            // For searching
            else {
                string field_to_search;
                switch(search_indiactor) {
                    case 0: field_to_search = row[1]; break; // name
                    case 1: field_to_search = row[2]; break; // brand
                    case 2: field_to_search = row[3]; break; // category
                    default: continue;
                }

                if (convertToLower(field_to_search).find(search_lower) != string::npos) {
                    fin.close();
                    return prod_id;
                }
            }
        }
        catch (const std::exception& e) {
            continue; // Skip rows with conversion errors
        }
    }

    fin.close();
    return 0;
}


void product::printProd(int prod_id)
{
    string myString = to_string(prod_id);
    read_record(myString,4);

    // Display general product description
cout << "==============================" << endl;
cout << "  Product General Description " << endl;
cout << "==============================" << endl;
cout << "Name       : " << Display[0].name << endl;
cout << "Brand      : " << Display[0].brand << endl;
cout << "Category   : " << Display[0].category << endl;
cout << "Warranty   : " << Display[0].warranty_year << " year(s)" << endl;
cout << "------------------------------" << endl << endl;

}

