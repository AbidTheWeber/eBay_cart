#include <string>
using namespace std;
#ifndef USER_HPP
#define USER_HPP


class User{

private:
    string email; 
    string password; //update this password once user id is fetched for checkPassword function !
    string address;
    string id;
    const string filename ="user_record.csv";
public:
    bool checkid(const string &id) ; //called when login id(user_account which is alphabet+number) is checked 
    bool registerID(string &username); //called when signup is needed
    void updatePassword(const string &pass); //same function will be called to set new password & update old password
    bool checkPassword(const string &password); //once user id is matched , password is checked 
    string getName();
    string getAddress();

};

#endif
