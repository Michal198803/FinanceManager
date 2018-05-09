
#include "UsersFile.h"
#include "Markup.h"
#include "HomeBudget.h"

vector<User> UsersFile::getUsersVect() {
    return usersVect;
}

void UsersFile::setUsersVect(vector<User> usersVect) {
    UsersFile::usersVect = usersVect;
}

int UsersFile::getLogUserId() {
    return logUserId;
}

void UsersFile::setLogUserId(int logUserId) {
    UsersFile::logUserId = logUserId;
}

vector<User> loadAllUsersFromFile(vector<User> &usersVect) {
    User login;
    CMarkup xml;

    xml.Load("users.xml");

    while (xml.FindElem("User")) {
        xml.IntoElem();

        xml.FindElem(MCD_T("UserId"));
        string iduser = MCD_T("UserId");
        int id = atoi(MCD_2PCSZ(xml.GetData()));
        login.setIdUser(id);
        xml.FindElem("User");
        login.setLogin(xml.GetData());
        xml.FindElem("Password");
        login.setPassword(xml.GetData());
        xml.FindElem("Name");
        login.setName(xml.GetData());
        xml.FindElem("Surname");
        login.setSurname(xml.GetData());
        xml.OutOfElem();
        usersVect.push_back(login);
    }
    return usersVect;
}


void UsersFile::registration() {
    loadAllUsersFromFile(usersVect);
    CMarkup xml;
    string password;
    string login;
    string name;
    string surname;
    int userIdInt;
    string userId;


    this->getUsersVect().size();// ilośc loginów w wketorze


    if (this->getUsersVect().size() == 0)
        userIdInt = 1;
    else
        userIdInt = this->getUsersVect()[this->getUsersVect().size() - 1].getIdUser() + 1;


    cout << "Insert your future login: ";
    cin >> login;

    cout << "Insert your future password: ";
    cin >> password;
    cout << "Insert your name: ";
    cin >> name;
    cout << "Insert your surname: ";
    cin >> surname;
    char string[10] = {0};
    userId += itoa(userIdInt, string, 10);
    xml.Load("users.xml");
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", userId);
    xml.AddElem("User", login);
    xml.AddElem("Password", password);
    xml.AddElem("Name", name);
    xml.AddElem("Surname", surname);
    xml.OutOfElem();
    xml.Save("users.xml");

}

void UsersFile::logOn() {
    UsersFile userFile;
    User login;
    HomeBudget homeBudgetObj;
    string enteredLogin, enteredPassword;
    loadAllUsersFromFile(usersVect);

    cout << "Enter your login: " << endl;
    cin >> enteredLogin;


    for (int i = 0; i < this->getUsersVect().size(); i++) {
        if (this->getUsersVect()[i].getLogin() == enteredLogin) {
            cout << "Enter your password: " << endl;
            cin >> enteredPassword;
            if (this->getUsersVect()[i].getPassword() == enteredPassword) {
                userFile.setLogUserId(usersVect[i].getIdUser());
                homeBudgetObj.menu(userFile);

            }
        }
    }
}

void UsersFile::changeLoginPassword() {
    User login;
    CMarkup xml;
    string enteredPassword;

    vector<User> loginsTemp = loadAllUsersFromFile(this->usersVect);
    for (int i = 0; i < this->usersVect.size(); i++) {

        if (this->usersVect[i].getIdUser() == this->logUserId) {
            cout << "Set the new password" << endl;
            getline(cin, enteredPassword);
            usersVect[i].setPassword(enteredPassword.c_str());
        }

    }

    remove("users.xml");

    for (int i = 0; i < usersVect.size(); i++) {
        xml.Load("users.xml");
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserId", usersVect[i].getIdUser());
        xml.AddElem("User", usersVect[i].getLogin());
        xml.AddElem("Password", usersVect[i].getPassword());
        xml.AddElem("Name", usersVect[i].getName());
        xml.AddElem("Surname", usersVect[i].getSurname());
        xml.OutOfElem();
        xml.Save("users.xml");
    }

    cout << "Password changed successfully" << endl;
    logOn();

}


