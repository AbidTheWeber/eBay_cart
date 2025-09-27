#include <string>
using namespace std;
#ifndef USER_HPP
#define USER_HPP


class User{

private:
    string email;
    string password;
    string address;
    const string filepath ="";
public:
    bool checkid(const string id) ;
    bool registerID(string username);
    void updatePassword(const string pass); 





};

#endif
