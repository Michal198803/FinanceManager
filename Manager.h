#include <iostream>
#include <vector>
#include "Login.h"
#include "Incomes.h"
#include "Expenses.h"
#ifndef MANAGER_H_
#define MANAGER_H_

namespace std {

class Manager {



private:

	int wybor;
	int numerIdZalogowanegoUsera = 0;
	int idDoUsuniecia = 0;
	string loginWprowadzony;
	vector<Login> logins;
    vector<Incomes> incomes;
    vector<Expenses> expenses;

public:

	void logOn(int &numerIdZalogowanegoUsera);

	void registration(int numerIdZalogowanegoUsera);

  void addNewIncome(int &numerIdZalogowanegoUsera);
    void addNewExpense(int &numerIdZalogowanegoUsera);
  void  showBalance(int &numerIdZalogowanegoUsera, int &balancePeriod);
    void  changeLoginPassword(int &numerIdZalogowanegoUsera);
};

} /* namespace std */

#endif /* MANAGER_H_ */
