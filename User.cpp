#include <iostream>
#include "User.h"

using namespace std;

string User::getLogin() {
    return login;

}

void User::setLogin(string login) {
    this->login = login;
}

string User::getPassword() {
    return password;

}

void User::setPassword(string password) {
    this->password = password;
}

int User::getIdUser() {
    return idUser;

}

void User::setIdUser(int idUser) {
    this->idUser = idUser;
}

string User::getName() {
    return name;

}

void User::setName(string name) {
    this->name = name;
}

string User::getSurname() {
    return surname;

}

void User::setSurname(string surname) {
    this->surname = surname;
}
