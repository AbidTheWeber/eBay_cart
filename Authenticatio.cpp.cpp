#include<iostream>
#include<iomanip>
#include"user.h"
using namespace std;

int main()
{

    User person1;
    string id , username , password;
    bool success = false;
    cout<<"Welcome to eBay"<<endl;
    cout<<"Please enter your id ?"<<endl;
    getline(cin,id);
    if(!person1.checkid(id))
    {
        cout<<"You are not registered!"<<endl;
        cout<<"Sign up now! \n Please create a username:";

        while(!success)
        getline(cin,username);
        if(person1.registerID(username))
        {
            getline(cin,password);
            person1.updatePassword(password);
            success=true;
        }
        else
        {
            cout<<"This username is already taken. Please use another !"<<endl;
            
        }

    }
    else
    {
        


    }


    return 0;
}