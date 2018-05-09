
#include "Expense.h"


int Expense::getUserId() {
    return userId;
}

void Expense::setUserId(int userId) {
    Expense::userId = userId;
}

int Expense::getExpenseId() {
    return expenseId;
}

void Expense::setExpenseId(int expenseId) {
    Expense::expenseId = expenseId;
}

const string Expense::getExpenseName() {
    return expenseName;
}

void Expense::setExpenseName(string expenseName) {
    Expense::expenseName = expenseName;
}

Date Expense::getDateObj(){

    return dateObj;
}

void Expense::setDateObj(Date dateObj) {
    Expense::dateObj = dateObj;
}

 Amount Expense::getAmountObj()  {
    return amountObj;
}

void Expense::setAmountObj( Amount amountObj) {
    Expense::amountObj = amountObj;
}
