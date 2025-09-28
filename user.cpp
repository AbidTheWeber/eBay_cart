#include<iostream>
#include<iomanip>
#include"user.h"
using namespace std;


bool User::checkid(const string &id) 
{
    if (id.empty()) return false;
    if (id.size() < 3 || id.size() > 20) return false;
    if (!isalpha(static_cast<unsigned char>(id[0]))) return false;
    for (char ch : id)
    {
        if (!(isalnum(static_cast<unsigned char>(ch)) || ch == '_' || ch == '-'))
        {
            return false;
        }
    }
    return true;
}

bool User::registerID(string &username)
{
    cout << "Enter user id: ";
    string input;
    if (!(cin >> input)) return false;

    while (!checkid(input) || registeredIds.count(input) > 0)
    {
        if (!checkid(input))
        {
            cout << "Invalid id. Use 3-20 characters, start with letter, [A-Za-z0-9_-] only.\n";
        }
        else
        {
            cout << "This id is already taken. Try another.\n";
        }
        cout << "Enter user id: ";
        if (!(cin >> input)) return false;
    }

    registeredIds.insert(input);
    username = input;
    return true;
}
