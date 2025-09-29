#include<iostream>
#include<iomanip>
#include"user.h"
#include"product.h"
#include"listing.h"
#include"search.h"
#include"Cart.h"
#include"Checkout.h"//will be implemented in our real product
#include"Authntication.h"

using namespace std;

void showMenu();
int showCartOption();


int main()
{
    User active1;
    Authentication session1;
    session1.getUser(&active1);

    cout << "***Welcome to eBay!***" << endl << endl;

    if(session1.login() != 0) {
        cout << "Login failed. Exiting..." << endl;
        return 1;
    }

    // Create cart and other objects AFTER successful login
    product show1;
    search result1;
    listing market1;
    Cart save_place(active1.getName());  // Now username will be available

    // Pass objects to search
    result1.getProduct(&show1);
    result1.getMarket(&market1);
    result1.getCart(&save_place);

    int user_choice;
    //menu that is shown to user!
    do
    {
        int cart_option=0 , listing_id=0 , newQty=0 ;
        char choice;
        showMenu();
        cin>>user_choice;
        switch(user_choice)
        {
        case 1:
            save_place.showCartSummary();
        do{
                cart_option=showCartOption();
                switch(cart_option) 
                {
                case 1:
                    cout << "Enter listing ID to delete.\n";
                    cin>>listing_id;
                     if (listing_id < 0) 
                      cout << "Invalid ID.\n";
                    else
                        save_place.deleteProductfromCart(listing_id);
                    break;

                case 2:
                    cout << "Enter listing ID and new quantity.\n";
                    cin>>listing_id>>newQty;
                    if (newQty < 0 || listing_id<0) 
                         cout << "Invalid number!\n";
                    else
                        save_place.updateQuantityinCart(listing_id,newQty);
                    break;
                case 3:
                    cout << "Showing cart summary...\n";
                    save_place.showCartSummary();
                    break;

                case 4:
                    cout << "Clear cart? (y/n)\n";
                    cout<<"##Notice: Once cart is deleted, It can't be undone!\n";
                    cin>>choice;
                    if(choice =='y')
                        save_place.clearCart();
                    else
                        cout<<"Retaining cart!\n";
                    break;

                case 0:
                    cout << "Saving cart and returning to main menu...\n";
                    break;

                default:
                    cout << "Invalid option. Try again.\n";
                }
        }while(cart_option!=0);
        break;
        case 2:
            cout<<"calling checkout module..."<<endl;
            cout<<"Logistics under construction ! Please stick to enjoy seamless shopping with us \n $$ We're luancing soon!! \n";
            break;
        case 3:
            result1.searchOption();
            cout<<"\n";
            break;
        case 0:
            cout << "Saving your cart before logout..." << endl;
            save_place.generateCartfile();   // writes cart to file
             cout << "Goodbye!" << endl;
            break;
        default:
            cout<<"Invalid option!! Please select correct menu\n";
        }
    }while(user_choice != 0);

    return 0;
}



void showMenu()
{
    //menu that is shown to user !
    cout<<"\n\nPress 1 to see/edit the cart\n";
    cout<<"Press 2 to checkout\n";
    cout<<"Press 3 to search product\n";
    cout<<"Press 0 to logout\n";
}


    int showCartOption()
{
    int option;
    cout << "\n\n=========== Cart Menu ===========" << endl;
    cout << "Press 1 to delete a product from cart" << endl;
    cout << "Press 2 to update product quantity" << endl;
    cout << "Press 3 to view cart summary" << endl;
    cout << "Press 4 to clear the cart" << endl;
    cout << "Press 0 to go back to main menu" << endl;
    cout << "================================" << endl;
    cin>>option;
    if(option>=0 && option<=4)
        return option;
    else
    {
        cout<<"Invalid option!\n";
        return 0;
    }
}

    


