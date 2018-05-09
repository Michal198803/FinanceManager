

#include "Income.h"


int Income::getUserId()  {
    return userId;
}

void Income::setUserId(int userId) {
    Income::userId = userId;
}

int Income::getIncomeId()  {
    return incomeId;
}

void Income::setIncomeId(int incomeId) {
    Income::incomeId = incomeId;
}

 string Income::getIncomeName()  {
    return incomeName;
}

void Income::setIncomeName(string incomeName) {
    Income::incomeName = incomeName;
}

Date Income::getDateObj()  {
    return dateObj;
}

void Income::setDateObj( Date dateObj) {
    Income::dateObj = dateObj;
}

 Amount Income::getAmountObj()  {
    return amountObj;
}

void Income::setAmountObj( Amount &amountObj) {
    Income::amountObj = amountObj;
}
