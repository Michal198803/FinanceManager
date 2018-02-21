//
// Created by britenet on 2018-02-14.
//
#include <iostream>
#ifndef FINANCEMANAGER_INCOMES_H
#define FINANCEMANAGER_INCOMES_H

using namespace std;

class Incomes {

private:
    int userId,incomeId,date;
public:
    int getDate() const;

    void setDate(int date);

private:
    float amount;
    string incomeName;
public:
    const string &getIncomeName() const;

    void setIncomeName(const string &incomeName);

    int getUserId() const;

    void setUserId(int userId);

    int getIncomeId() const;

    void setIncomeId(int incomeId);

    int getAmount() const;

    void setAmount(int amount);





};





#endif //FINANCEMANAGER_INCOMES_H
