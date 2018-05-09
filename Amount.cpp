



#include "Amount.h"
#include <algorithm>
#include <vector>

float Amount::getAmount() {
    return amount;
}

void commaToDot(string &incomeAmount) {
    if (incomeAmount.find(',')) {
        replace(incomeAmount.begin(), incomeAmount.end(), ',', '.');
        puts(incomeAmount.c_str());
    }
}


bool Amount::dataValidation(string &incomeAmount) {

    for (int i = 0; i < incomeAmount.size(); i++) {

        if (incomeAmount[i] != '0' && incomeAmount[i] != '1' && incomeAmount[i] != '2'
            && incomeAmount[i] != '3' && incomeAmount[i] != '4'
            && incomeAmount[i] != '5' && incomeAmount[i] != '6'
            && incomeAmount[i] != '7' && incomeAmount[i] != '8'
            && incomeAmount[i] != '9' &&  incomeAmount[i] != ','
            && incomeAmount[i] != '.') {
            cout << "Amount should contains number value" << endl;

            return false;
        }
    }

    return true;
}

void Amount::enterAmount() {
    string incomeAmount;
    bool validation=false;

    while(validation==false) {
        cout << "Enter the income amount: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, incomeAmount);


        validation = this->dataValidation(incomeAmount);
    }


        commaToDot(incomeAmount);

    float amount = atof (incomeAmount.c_str());
    this->setAmount(amount);
    return;
}

void Amount::setAmount(float amount) {
    Amount::amount = amount;
}


