#include <iostream>
#include "Login.h"
using namespace std;

string Login::getLogin() {
	return login;

}

void Login::setLogin(string login) {
	this->login = login;
}
string Login::getPassword() {
	return password;

}

void Login::setPassword(string password) {
	this->password = password;
}

int Login::getIdUser() {
	return idUser;

}

void Login::setIdUser(int idUser) {
	this->idUser = idUser;
}

string Login::getName() {
	return name;

}

void Login::setName(string name) {
	this->name= name;
}
string Login::getSurname() {
	return surname;

}

void Login::setSurname(string surname) {
	this->surname = surname;
}
