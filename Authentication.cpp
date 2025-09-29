#include<iostream>
#include<iomanip>
#include<string>
#include"user.h"
#include"Authntication.h"
using namespace std;



int Authentication:: login()
{
    cin.clear();
    string password; //clears the temporary storage of password 
    string id ;
    int try_time=0;
    bool success = false;
    
    cout<<"Please enter your id :"<<endl;
    getline(cin,id);
    if(person1 == nullptr)
        return 1;
    if(!person1->checkid(id))
    {
        cout<<"You are not registered!"<<endl;
        cout<<"Sign up now! \n Please create a username:";

        while(!success)
        {
    
            getline(cin, id);
            if(person1->registerID(id))
            {
                /*cout << "Enter password: ";
                if(!getline(cin,password))
                return 1;
                person1->updatePassword(password);*/
                success=true;
                cout << "Registration successful!" << endl;
            }
            else
            {
                cout<<"This username is already taken. Please use another !"<<endl;  
            }
        }

    }
    else
    {
        cout<<"User_record found! Please enter your password :"<<endl;

         if(!getline(cin,password))
                return 1;
        while(!person1->checkPassword(password))
        {
            try_time++;
            cout<<"Wrong Password ! Please enter correct password :"<<endl;
    
            if(!getline(cin,password))
                return 1;
            if(try_time>2)
            {
                cout<<"You have tried 3 times with wrong password ! Aborting the programme...\n";
                return 1;
            }
        }
        
    }


    return 0;
}