#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include"user.h"
using namespace std;

bool User::checkid(const string &id) 
{
    cin.clear();
    fstream fin;
    fin.open(filename, ios::in);
    
    if(!fin.is_open()) {
        return false;
    }

    vector<string> row;
    string line, word;

    // Skip header
    getline(fin, line);

    while(getline(fin, line)) {
        stringstream s(line);
        row.clear();
        
        while(getline(s, word, ',')) {
            row.push_back(word);
        }
        
        if(row[0] == id) {
            this->id = id;
            this->password = row[1];
            this->email = row[2];
            this->address = row[3];
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

bool User::registerID(string &username)
{
    cin.clear();
    // Check if username already exists
    if(checkid(username)) {
        return false;
    }

    // If username is unique, save it
    this->id = username;
    cout << "Enter email: ";
    getline(cin, this->email);
    cout << "Enter address: ";
    getline(cin, this->address);
    cout << "Enter password: ";
    string pass;
    getline(cin, pass);
    this->password = pass;

    // Save to file
    ofstream fout;
    fout.open(filename, ios::app);
    if(!fout.is_open()) {
        cout << "Error: Could not open file to register user\n";
        return false;
    }

    // Write new user data
    fout << id << "," << password << "," << email << "," << address << endl;
    fout.close();
    return true;
}

void User::updatePassword(const string &pass)
{
    cin.clear();
    this->password = pass;
    
    // Read all records
    vector<vector<string>> records;
    fstream fin;
    fin.open(filename, ios::in);
    string line, word;
    
    // Store header
    getline(fin, line);
    records.push_back({line});
    
    while(getline(fin, line)) {
        stringstream s(line);
        vector<string> row;
        while(getline(s, word, ',')) {
            row.push_back(word);
        }
        if(row[0] == this->id) {
            row[1] = pass; // Update password
        }
        records.push_back(row);
    }
    fin.close();

    // Write updated records back
    ofstream fout;
    fout.open(filename, ios::out);
    for(const auto &record : records) {
        for(size_t i = 0; i < record.size(); i++) {
            fout << record[i];
            if(i < record.size() - 1) fout << ",";
        }
        fout << endl;
    }
    fout.close();
}

bool User::checkPassword(const string &password)
{
    return this->password == password;
}

string User::getName()
{
    return this->id;
}

string User::getAddress()
{
    return this->address;
}


/*

bool User::checkid(const string &id) 
{}
bool User::registerID(string &username)
{}

void User::updatePassword(const string &pass)
{}
bool User::checkPassword(const string &password)
{}

string User::getName()
{}

string User::getAddress()
{}*/




