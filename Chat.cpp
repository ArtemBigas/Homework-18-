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
    cout << "Ваше имя: " << NamefromUser << endl;

    string NametoUser;

    bool k = false;//счетчик наличия введеного пользователя в списке зарегистрированных
    bool n = false;//счетчик наличия сообщений в истории
    
    fstream message_file = fstream("messages.txt", ios::in | ios::out);
    if (!message_file)
    {
        // Для создания файла используем параметр ios::trunc
        message_file = fstream("messages.txt", ios::in | ios::out | ios::trunc);
        fs::permissions("messages.txt",
            fs::perms::group_all | fs::perms::others_all,
            fs::perm_options::remove);//удаляем все права, кроме владельца

    }

    while (operat != '3')
    {
        cout << "Выберите команду: " << endl << "1 - написать сообщение" << endl << "3 - выйти в главное меню" << endl;
        cin >> operat;

        switch (operat)
        {
        case '1':
            cout << "Выберите получателя:" << endl;
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
                    cout << "Введите сообщение: ";
                    cin >> Message;
                    B.emplace_back(NamefromUser, NametoUser, Message);
                    if (message_file) {
                        User obj(NamefromUser, NametoUser, Message);
                        message_file.seekp(0, std::ios_base::end);
                        // Запишем данные по в файл
                        message_file << obj << endl;
                    }
                    else
                    {
                        cout << "Could not open file users.txt !" << '\n';

                    }
                };

            };
            if (k == false) cout << "Данный получатель незарегистрирован" << endl;
            k = false;
            break;
        
        default:

            std::cout << "Вы ввели неверную команду!" << std::endl;
            std::cout << std::endl;
            break;

        };


    };
};