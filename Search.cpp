#include <iostream>
#include <limits>
#include "search.h"
#include "product.h"
#include "listing.h"
#include "Cart.h"
using namespace std;



void search::showoption()
{
    cout<<"Please select the way you want to search:"<<endl;
    cout<<"press 1 to search by input"<<endl;
    cout<<"press 2 to search by brand"<<endl;
    cout<<"press 3 to search by category"<<endl;
    cout<<"press 0 to exit search"<<endl;
}

void search::searchOption()
{
    int option;
    char choice;
    
    do {
        showoption();
        if(!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if(option == 0) {
            return;
        }

        string input;
        int prod_num = 0;
        
        if(option >= 1 && option <= 3) {
            cout << "Enter search term: ";
            getline(cin, input);
            
            switch(option) {
                case 1:
                    prod_num = search_result->getIDname(input);
                    break;
                case 2:
                    prod_num = search_result->getIDbrand(input);
                    break;
                case 3:
                    prod_num = search_result->getIDcategory(input);
                    break;
            }

            if(prod_num == 0) {
                cout << "No products found matching your search.\n";
            } else {
                search_result->printProd(prod_num);
                marketplace->read_record(prod_num);
                marketplace->print_sell();
                addCart();
            }
        } else {
            cout << "Invalid option! Please select a valid menu item.\n";
        }
        
    } while(option != 0);
}

void search::addCart()
{
    int seller_num, quantity;
    char choice = 'n';
    
    do {
        cout << "Would you like to add this item to cart? (y/n): ";
        cin >> choice;
        
        if(tolower(choice) == 'y') {
            cout << "Enter seller number: ";
            if(cin >> seller_num) {
                cout << "Enter quantity: ";
                if(cin >> quantity) {
                    user_cart->addProductTocart(seller_num, quantity);
                    //cout << "Product added to cart successfully!\n";
                    return;
                }
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        }
    } while(tolower(choice) != 'n');
}



