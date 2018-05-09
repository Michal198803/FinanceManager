
#ifndef EXPENSE_H_
#define EXPENSE_H_

#include<iostream>
#include"Date.h"
#include"Amount.h"


using namespace std;

class Expense {
private:
    int userId, expenseId;
public:
    int getUserId();

    void setUserId(int userId);

    int getExpenseId();

    void setExpenseId(int expenseId);

    const string getExpenseName();

    void setExpenseName(string expenseName);

    Date getDateObj();

    void setDateObj(Date dateObj);

    Amount getAmountObj();

    void setAmountObj(Amount amountObj);

private:
    string expenseName;
    Date dateObj;
    Amount amountObj;


};

#endif /* EXPENSE_H_ */
