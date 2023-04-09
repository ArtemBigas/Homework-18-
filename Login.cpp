#include "User.h"
void User::Login(vector<User>& A, string name, string& login, string& password, vector<User::Message>& B, const string& _sender, string&  _receiver, string& _text)
{
    int n = 0;
    int k;
    cout << "Ётап авторизации" << endl;
    cout << "¬ведите Ћогин: ";
    cin >> login;
    cout << endl;
    cout << "¬ведите ѕароль: ";
    cin >> password;
    cout << endl;
    for (int i = 0; i < A.size(); i++)
    {
        if (login == A[i]._login)
        {
            n++; // отмечаем, что такой логин есть
            k = i;
        }
    }
    try
    {
        if (n == 0) { throw bad_sing(); }
        else if (A[k]._pass == password)
        {
            ChatMenu(A, B, name, login, _sender,  _receiver, _text);
        }
        else if (A[k]._pass != password)
        {
            throw bad_sing();
        }

    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}