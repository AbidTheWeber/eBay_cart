#include<iostream>
#include"search.h"
#include"product.h"
#include"listing.h"
#include"Cart.h"
using namespace std;


void search::searchOption()
{
    int option; char choice;
    showoption();
    cin>>option;
    while(option !=0)
  {
        int prod_num=0;
        string input;
        if(option == 1 ) 
        {
            cout<<"Enter product name you want to search: ";
            cin.ignore();
            getline(cin,input);
            prod_num = search_result->getIDbrand(input);
        }
        else if(option == 2)
        {
            cout<<"\nEnter product brand you want to search: ";
            cin.ignore();
            getline(cin,input);
            prod_num = search_result->getIDbrand(input);

        }
        else if(option == 3)
        {
            cout<<"\nEnter product category you want to search: ";
            cin.ignore();
            getline(cin,input);
            prod_num = search_result->getIDbrand(input);
        }

        if(prod_num == 0)
        {
            cout<<"Sorry no similar product found! Please try another product!\n";
        }
        
        else{
            search_result->printProd(prod_num);
            marketplace->read_record(prod_num);
            marketplace->print_sell();
              cout<<"\n\npress a if you want to add any product to cart\n";
              cout<<"press b if you want to like any product \n";
            cin>>choice;
            if(choice =='a')
            {
                addCart();
                marketplace->updateCartNum(prod_num);
            }
            else if(choice =='b')
            {
                cout<<"Please enter seller number to add like product !"<<endl;
                cout<<"##Comment & Rating feuature is rolling out soon! Stay tuned for exciting feautures!!##"<<endl;
                marketplace->updateLike(prod_num);

            }
        }
    showoption();
    cin>>option;
  }
  if(option==0)
    return;
}
    

void search::showoption()
{
    cout<<"Please select the way you want to search:"<<endl;
    cout<<"press 1 to search by input"<<endl;
    cout<<"press 2 to search by brand"<<endl;
    cout<<"press 3 to search by category"<<endl;
    cout<<"press 0 to exit search"<<endl;
}


void search::addCart()
{
    int seller_num , quantity , choice=0;
    while(choice != 0)
    {
        cout<<"Please enter seller number to add their product to your cart!(*only one seller number can be added at a time)"<<endl;
        cout<<"##Checkout now feuature is rolling out soon! Now please add to cart first then checkout##"<<endl;
        cin>>seller_num;
        cout<<"Please enter quantity :"<<endl;
        cin>>quantity;
        user_cart->addProductTocart(seller_num,quantity);
        cout<<"Press 0 if you are done with saving to cart !\n";
        cin>>choice;
    }
     return;
}