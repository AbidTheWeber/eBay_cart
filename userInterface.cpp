#include<iostream>
#include<iomanip>
#include"user.h"
#include"product.h"
#include"search.h"
#include"Cart.h"
#include"Checkout.h"
#include"Authntication.h"

using namespace std;

void showMenu();

int main()
{

    User active1;


    cout<<"***Welcome to eBay!***"<<endl<<endl;

    int user_choice;
    //menu that is shown to user !
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
            cout<<"checkout module feautures: select product to checkout from cart , show total bill , show order confirmation.Inside: Update stock & sale of product \n";
            break;
        case 3:
            cout<<"calling search product module!"<<endl;
            cout<<"search product module feautures: search prodcut by name, add to cart , like option. Inside: Update cart and update product file with like\n";
            cout<<"Product are shown based on binary search by name and then sorted based on like & sale percentage !\n";
            cout<<"basic programme so no filter or instant checkout. Add to cart first then checkout!! , haha!\n";
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
