#include <iostream>
#include <vector>
#include "User.h"
#include "Incomes.h"
#include "Expenses.h"
#include "UsersFile.h"
#include "Incomes.h"
#include "Date.h"
#ifndef MANAGER_H_
#define MANAGER_H_

namespace std {

    class HomeBudget {


    private:

        int wybor;
        Incomes incomes;
        Expenses expenses;
       string dataBegin, dataEnd;
        Date dateObj;
    public:


        void addNewIncome(UsersFile &userFile);

        void addNewExpense(UsersFile &userFile);

        void showBalance(UsersFile &usersFile, int &balancePeriod);

        void changeLoginPassword(int &numerIdZalogowanegoUsera);

        void menu(UsersFile &usersFile);
        vector<Income>selectByMonthIncome(Incomes &incomes, int &balancePeriod);
        vector<Expense>selectByMonthExpense(Expenses &expenses, int &balancePeriod);
    };

} /* namespace std */

#endif /* MANAGER_H_ */
