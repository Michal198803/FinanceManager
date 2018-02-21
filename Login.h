
#include <iostream>


#ifndef LOGIN_H_
#define LOGIN_H_

using namespace std;
class Login {




private:
	int idUser;
	string login;
	string password;
	string name;
	string surname;


public:
	string getLogin();
	void setLogin(string login);
	string getPassword();
	void setPassword(string password);
	int getIdUser();
	void setIdUser(int idUsera);
		string getName();
			void setName(string login);
			string getSurname();
			void setSurname(string password);

};

#endif /* LOGIN_H_ */
