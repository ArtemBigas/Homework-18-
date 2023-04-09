#include "User.h"
User::Message::Message(const string& namefrom, string& nameto, string& message)
{
    _sender = namefrom;
     _receiver = nameto;
    _text = message;
}
fstream& operator >>(fstream& is, User::Message& obj)
{
    
    is >> obj._sender;
    is >> obj._receiver;
    is >> obj._text;
    return is;
}
ostream& operator <<(ostream& os, const User::Message& obj)
{
    os << obj._sender;
    os << ' ';
    os << obj._receiver;
    os << ' ';
    os << obj._text;
    return os;
}
void User::ChatMenu(vector<User >& A, vector<User::Message>& B, string name, string& login, const string& Namefrom, string& Nameto, string& Message)
{
    char operat = '0';

    string NamefromUser = login;
    cout << "���� ���: " << NamefromUser << endl;

    string NametoUser;

    bool k = false;//������� ������� ��������� ������������ � ������ ������������������
    bool n = false;//������� ������� ��������� � �������
    
    fstream message_file = fstream("messages.txt", ios::in | ios::out);
    if (!message_file)
    {
        // ��� �������� ����� ���������� �������� ios::trunc
        message_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);
        fs::permissions("messages.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//������� ��� �����, ����� ���������

    }

    while (operat != '3')
    {
        cout << "�������� �������: " << endl << "1 - �������� ���������" << endl << "3 - ����� � ������� ����" << endl;
        cin >> operat;

        switch (operat)
        {
        case '1':
            cout << "�������� ����������:" << endl;
            for (int i = 0; i < A.size(); ++i)
            {
                cout << A[i]._login << endl;
            }
            cin >> NametoUser;

            for (int i = 0; i < A.size(); ++i)
            {
                if (A[i]._login == NametoUser)
                {
                    k = true;
                    cout << "������� ���������: ";
                    cin >> Message;
                    B.emplace_back(NamefromUser, NametoUser, Message);
                    if (message_file) {
                        User obj(NamefromUser, NametoUser, Message);
                        message_file.seekp(0, std::ios_base::end);
                        // ������� ������ �� � ����
                        message_file << obj << endl;
                    }
                    else
                    {
                        cout << "Could not open file users.txt !" << '\n';

                    }
                };

            };
            if (k == false) cout << "������ ���������� �����������������" << endl;
            k = false;
            break;
        
        default:

            std::cout << "�� ����� �������� �������!" << std::endl;
            std::cout << std::endl;
            break;

        };


    };
};