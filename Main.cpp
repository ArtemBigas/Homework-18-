#include "User.h"



int main()
{
    system("chcp 1251");
    std::vector<User> UserArr;//������ ��� �������� ������ � ������
    std::vector<User::Message> MessengerArr;//������ ��� �������� ���������
    User Personal;
    string Name;
    string Log;
    string Pass;
    string NameTo;
    string NameFrom;
    string Message;
    
    Personal.StartMenu(UserArr, Name,Log, Pass, MessengerArr, NameFrom, NameTo, Message);


    return 0;
};