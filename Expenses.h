//
// Created by britenet on 2018-02-14.
//
#include <iostream>
#ifndef FINANCEMANAGER_EXPENSES_H
#define FINANCEMANAGER_EXPENSES_H

using namespace std;

class Expenses {


private:
    int userId, expenseId,date;
    float amount;
public:
    int getUserId() const;

    void setUserId(int userId);

    int getExpenseId() const;

    int getDate() const;

    void setDate(int date);

    void setExpenseId(int expenseId);

   float getAmount() const;

    void setAmount(float amount);

    const string &getExpenseName() const;

    void setExpenseName(const string &expenseName);



private:

    string expenseName;



};


#endif //FINANCEMANAGER_EXPENSES_H