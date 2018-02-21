
#include "Expenses.h"
#include "Incomes.h"

int Expenses::getUserId() const {
    return userId;
}

void Expenses::setUserId(int userId) {
    Expenses::userId = userId;
}

int Expenses::getExpenseId() const {
    return expenseId;
}

void Expenses::setExpenseId(int expenseId) {
    Expenses::expenseId = expenseId;
}

float Expenses::getAmount() const {
    return amount;
}

void Expenses::setAmount(float amount) {
    Expenses::amount = amount;
}

const string &Expenses::getExpenseName() const {
    return expenseName;
}

void Expenses::setExpenseName(const string &expenseName) {
    Expenses::expenseName = expenseName;
}

int Expenses::getDate() const {
    return date;
}

void Expenses::setDate(int date) {
    Expenses::date = date;
}




