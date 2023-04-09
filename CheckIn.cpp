#include "User.h"
void  User::Registration(vector<User>& A, string name, string& login, string& password)
{
    fstream user_file = fstream("users.txt", ios::in | ios::out);
    if (!user_file)
    {
        // Для создания файла используем параметр ios::trunc
        user_file = fstream("users.txt", ios::in | ios::out | ios::trunc);//файл для хранения всех данных пользователей
        fs::permissions("users.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//удаляем все права, кроме владельца

    }
    fstream login_file = fstream("logins.txt", ios::in | ios::out);//файл для хранения Логинов
    if (!login_file)
    {
        // Для создания файла используем параметр ios::trunc
        login_file = fstream("logins.txt", ios::in | ios::out | ios::trunc);
        fs::permissions("logins.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//удаляем все права, кроме владельца

    }
    cout << "Этап регистрации" << endl;
    cout << "Введите Логин: ";
    cin >> login;
        cout << endl;
        string words;//переменная для поиска похожего логина
        ifstream find_file("logins.txt");//переменная для поиска похожего логина
        try
        {
            while (find_file >> words)
                if (words == login) {

                    throw "Такой login уже зарегистрирован!";
                }
            find_file.close();
        cout << "Введите Имя: ";
        cin >> name;
        cout << endl;
        cout << "Введите Пароль: ";
        cin >> password;
        cout << endl;
        A.emplace_back(name, login, password);

        if (user_file) {
            User obj(name, login, password);
            user_file.seekp(0, std::ios_base::end);
            // Запишем данные по в файл
            user_file << obj << endl;
            User obj_login(name, login = "0", password= "0");
            login_file.seekp(0, std::ios_base::end);
            // Запишем данные по в файл
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