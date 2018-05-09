
#include<iostream>
#include"Date.h"
#include"Amount.h"

#ifndef INCOME_H_
#define INCOME_H_
using namespace std;

class Income {
public:
private:
    int userId, incomeId;
public:
    int getUserId() ;

    void setUserId(int userId);

    int getIncomeId() ;

    void setIncomeId(int incomeId);

  string getIncomeName() ;

    void setIncomeName(string incomeName);

    Date getDateObj() ;

    void setDateObj( Date dateObj);

   Amount getAmountObj();

    void setAmountObj( Amount &amountObj);

private:
    string incomeName;
    Date dateObj;
    Amount amountObj;

};

#endif /* INCOME_H_ */
