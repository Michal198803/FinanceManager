
#include <iostream>
#include <vector>
#include "Expense.h"
#include "UsersFile.h"
#ifndef FINANCEMANAGER_EXPENSES_H
#define FINANCEMANAGER_EXPENSES_H

using namespace std;

class Expenses {

private:
    vector<Expense> expensesVect;
public:
   vector<Expense> getExpensesVect() ;
    void addNewExpense(vector<Expense>&expensesVect,UsersFile &usersFile);
    void loadExpensesFromXmlToVector();

};


#endif //FINANCEMANAGER_EXPENSES_H
