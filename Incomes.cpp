//
// Created by britenet on 2018-02-14.
//

#include "Incomes.h"


const string &Incomes::getIncomeName() const {
    return incomeName;
}

void Incomes::setIncomeName(const string &incomeName) {
    Incomes::incomeName = incomeName;
}


int Incomes::getUserId() const {
    return userId;
}

void Incomes::setUserId(int userId) {
    Incomes::userId = userId;
}

int Incomes::getIncomeId() const {
    return incomeId;
}

void Incomes::setIncomeId(int incomeId) {
    Incomes::incomeId = incomeId;
}

int Incomes::getAmount() const {
    return amount;
}

void Incomes::setAmount(int amount) {
    Incomes::amount = amount;
}

int Incomes::getDate() const {
    return date;
}

void Incomes::setDate(int date) {
    Incomes::date = date;
}
