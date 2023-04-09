#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream> 	// Для типа ifstream 
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class User
{
    string _name;
    string _login;
    string _pass;
public:
    User() {};
    User(const string& login);
    User(string name, const string& login, string& password);
    friend fstream& operator >>(fstream& is, User& obj);
    friend ostream& operator <<(ostream& os, const User& obj);
    class Message {
        string _sender;
        string  _receiver;
        string _text;
    public:
        Message() {};
        Message(const string& namefrom, string& nameto, string& message);
        friend fstream& operator >>(fstream& is, User::Message& obj);
        friend ostream& operator <<(ostream& os, const User::Message& obj);
    };
    void StartMenu(vector<User >& A, string name, string& login, string& password, vector<User::Message>& B, const string& Namefrom, string& Nameto, string& Message);
    void ChatMenu(vector<User >& A, vector<User::Message>& B, string name, string& login, const string& Namefrom, string& Nameto, string& Message);
    void  Registration(vector<User >& A, string name, string& login, string& password);
    void  Login(vector<User >& A, string name, string& login, string& password, vector<User::Message>& B, const string& Namefrom, string& Nameto, string& Message);
   
};



class bad_sing : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "неверный логин или пароль";
        std::cout << std::endl;
    }
};
