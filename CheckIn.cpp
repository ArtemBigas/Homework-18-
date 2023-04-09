#include "User.h"
void  User::Registration(vector<User>& A, string name, string& login, string& password)
{
    fstream user_file = fstream("users.txt", ios::in | ios::out);
    if (!user_file)
    {
        // ��� �������� ����� ���������� �������� ios::trunc
        user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);//���� ��� �������� ���� ������ �������������
        fs::permissions("users.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//������� ��� �����, ����� ���������

    }
    fstream login_file = fstream("logins.txt", ios::in | ios::out);//���� ��� �������� �������
    if (!login_file)
    {
        // ��� �������� ����� ���������� �������� ios::trunc
        login_file = fstream("logins.txt", ios::in | ios::out | ios::trunc);
        fs::permissions("logins.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//������� ��� �����, ����� ���������

    }
    cout << "���� �����������" << endl;
    cout << "������� �����: ";
    cin >> login;
        cout << endl;
        string words;//���������� ��� ������ �������� ������
        ifstream find_file("logins.txt");//���������� ��� ������ �������� ������
        try
        {
            while (find_file >> words)
                if (words == login) {

                    throw "����� login ��� ���������������!";
                }
            find_file.close();
        cout << "������� ���: ";
        cin >> name;
        cout << endl;
        cout << "������� ������: ";
        cin >> password;
        cout << endl;
        A.emplace_back(name, login, password);

        if (user_file) {
            User obj(name, login, password);
            user_file.seekp(0, std::ios_base::end);
            // ������� ������ �� � ����
            user_file << obj << endl;
            User obj_login(name, login = "0", password= "0");
            login_file.seekp(0, std::ios_base::end);
            // ������� ������ �� � ����
            login_file << obj_login << endl;
        }
        else
        {
            cout << "Could not open file users.txt !" << '\n';

        }
        }
        catch (const char* exception)
        {
            std::cout << std::endl;
            std::cout << exception << std::endl;
            std::cout << std::endl;
        }
    
}