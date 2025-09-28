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

int product::read_record(const string &search_term , int search_indiactor)
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
        int count=0 , prod_num=0;
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

        if(search_indiactor==4)
        {
            if(search_term==row[0])
            {
                Display[0].id=stoi(row[0]);
                Display[0].name=row[1];
                Display[0].brand=row[2];
                Display[0].category=row[3];
                Display[0].warranty_year=stoi(row[4]);
            }
         return;
        }
        
        
        // convert string to integer for return
        prod_num = stoi(row[0]);


        if (search_indiactor == 0)
        {
            if(search_term == row[1])
            {
                return prod_num;
            }
        }
        else if(search_indiactor == 1)
        {
             if(search_term == row[2])
            {
                return prod_num;
            }

        }
        else if(search_indiactor == 2)
        {
            if(search_term == row[3])
            {
                return prod_num;
            }

        }
    }
    fin.close();
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