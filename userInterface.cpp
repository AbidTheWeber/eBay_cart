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


int main()
{
    //Instantation of classes 
    User active1;
    Authentication session1;
    product show1;
    search result1;
    listing market1;
    Cart save_place(active1.getName());


    //passing the class to destinations
    session1.getUser(&active1);
    result1.getProduct(&show1);
    result1.getMarket(&market1);
    result1.getCart(&save_place);



    cout<<"***Welcome to eBay!***"<<endl<<endl;

    session1.login();

    int user_choice;
    //menu that is shown to user!
    do
    {
        showMenu();
        cin>>user_choice;
        switch(user_choice)
        {
        case 1:
            cout<<"calling cart module!"<<endl;
            cout<<"Cart module feautures: delete prodcut, change quality ,CLEAR CART, see sumarry at the end. Inside: save cart to user file\n";
            break;
        case 2:
            cout<<"calling checkout module!"<<endl;
            cout<<"Logistics under construction ! Please stick to enjoy seamless shopping with us \n $$ We're luancing soon!! \n";
            break;
        case 3:
            result1.searchOption();
            cout<<"\n";
            break;
        case 0:
            cout<<"Logging out..!Bye!\n";
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


