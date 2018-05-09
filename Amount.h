

#ifndef AMOUNT_H_
#define AMOUNT_H_

#include <iostream>

using namespace std;

class Amount {

private:
    float amount;
public:
    float getAmount();

    void setAmount(float amount);

    bool dataValidation(string &incomeAmount);

    void enterAmount();
};

#endif /* AMOUNT_H_ */
