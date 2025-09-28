#ifndef USER_H
#define USER_H

#include <string>
#include <set>

using namespace std;

class User
{
private:
    string email;
    string password;
    string address;
    const string filepath = "";
    set<string> registeredIds;

public:
    bool checkid(const string &id);
    bool registerID(string &username);
    void updatePassword(const string pass);
};

#endif
