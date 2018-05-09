
#include "Incomes.h"
#include "Markup.h"

vector<Income> Incomes::getIncomesVect() {
    return incomesVect;
}

void Incomes::loadIncomesFromXmlToVector() {

    Income income;
    CMarkup xml;

    xml.Load("incomes.xml");

    while (xml.FindElem("Income")) {
        xml.IntoElem();
        xml.FindElem(MCD_T("UserId"));
        int idUser = atoi(MCD_2PCSZ(xml.GetData()));
        income.setUserId(idUser);
        xml.FindElem(MCD_T("Id"));
        int id = atoi(MCD_2PCSZ(xml.GetData()));
        income.setIncomeId(id);
        xml.FindElem("Name");
        income.setIncomeName(xml.GetData());
        xml.FindElem("Date");

        Date dateObj;
        dateObj.setDate(xml.GetData());
        income.setDateObj(dateObj);

        xml.FindElem("Amount");

        float incomeAmount =  atof(MCD_2PCSZ(xml.GetData()));;

        Amount amountObj;
        amountObj.setAmount(incomeAmount);
income.setAmountObj(amountObj);
        xml.OutOfElem();


       this->incomesVect.push_back(income);
    }
}


void Incomes::addNewIncome(vector<Income> &incomesVect, UsersFile &usersFile) {
    string date;
    this->loadIncomesFromXmlToVector();
    Date dateObj;
    Amount amountObj;

    int numerIdZalogowanegoUsera;
    int incomeIdInt;
    int incomeNumber = this->incomesVect.size();

    if (this->getIncomesVect().size() == 0)
        incomeIdInt = 1;
    else
        incomeIdInt = this->incomesVect[incomeNumber - 1].getIncomeId() + 1;

    CMarkup xml;
    string userId, incomeId, incomeName, incomeDate, incomeAmount;
    incomeId = to_string(incomeIdInt);
    userId = to_string(numerIdZalogowanegoUsera);
    cout << "Enter the income name: " << endl;
    cin.clear();
    cin.sync();
    getline(cin, incomeName);
    xml.Load("incomes.xml");
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", usersFile.getLogUserId());
    xml.AddElem("Id", incomeId);
    xml.AddElem("Name", incomeName);
    dateObj.setDate(dateObj.enterTheDate(date));

    xml.AddElem("Date", dateObj.getDate());
    amountObj.enterAmount();
    xml.AddElem("Amount", to_string(amountObj.getAmount()));
    xml.OutOfElem();
    xml.Save("incomes.xml");
    cout << "New income added.";


}
