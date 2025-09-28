#ifndef AUTHEN_HPP
#define AUTHEN_HPP
#include<string>

class User;

class Authentication
{
    private:
    User* person1 = nullptr; 

    public :
    int login();
    void getUser(User* obj)
    {
       person1 = obj;
    }

};
#endif