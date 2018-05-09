
#include <iostream>
#include <vector>
#include "Income.h"
#include "UsersFile.h"
#ifndef FINANCEMANAGER_INCOMES_H
#define FINANCEMANAGER_INCOMES_H

using namespace std;

class Incomes {

private:
    vector<Income> incomesVect;
public:
  vector<Income> getIncomesVect();

    void setIncomesVect(vector<Income> &incomesVect);

    void addNewIncome(vector<Income>&incomesVect,UsersFile &usersFile);
    void loadIncomesFromXmlToVector();





};


#endif //FINANCEMANAGER_INCOMES_H
