
#include "Expenses.h"
#include "Markup.h"


vector<Expense> Expenses::getExpensesVect() {
	return expensesVect;
}


void Expenses::loadExpensesFromXmlToVector() {

	Expense expense;
	CMarkup xml;

	xml.Load("expenses.xml");

	while (xml.FindElem("Expense")) {
		xml.IntoElem();
		xml.FindElem(MCD_T("UserId"));
		int idUser = atoi(MCD_2PCSZ(xml.GetData()));
		expense.setUserId(idUser);
		xml.FindElem(MCD_T("Id"));
		int id = atoi(MCD_2PCSZ(xml.GetData()));
		expense.setExpenseId(id);
		xml.FindElem("Name");
		expense.setExpenseName(xml.GetData());
		xml.FindElem("Date");

		Date dateObj;
		dateObj.setDate(xml.GetData());
		expense.setDateObj(dateObj);

		xml.FindElem("Amount");

		float expenseAmount =  atof(MCD_2PCSZ(xml.GetData()));;

		Amount amountObj;
		amountObj.setAmount(expenseAmount);
		expense.setAmountObj(amountObj);
		xml.OutOfElem();


		this->expensesVect.push_back(expense);
	}
}


void Expenses::addNewExpense(vector<Expense> &expensesVect, UsersFile &usersFile) {
	string date;
	this->loadExpensesFromXmlToVector();
	Date dateObj;
	Amount amountObj;

	int numerIdZalogowanegoUsera;
	int expenseIdInt;
	int expenseNumber = this->expensesVect.size();

	if (this->expensesVect.size() == 0)
		expenseIdInt = 1;
	else
		expenseIdInt = this->expensesVect[expenseNumber - 1].getExpenseId() + 1;

	CMarkup xml;
	string userId, expenseId, expenseName, expenseDate, expenseAmount;
	expenseId = to_string(expenseIdInt);
	userId = to_string(numerIdZalogowanegoUsera);
	cout << "Enter the expense name: " << endl;
	cin.clear();
	cin.sync();
	getline(cin, expenseName);
	xml.Load("expenses.xml");
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("UserId", usersFile.getLogUserId());
	xml.AddElem("Id", expenseId);
	xml.AddElem("Name", expenseName);
	dateObj.setDate(dateObj.enterTheDate(date));

	xml.AddElem("Date", dateObj.getDate());
	amountObj.enterAmount();
	xml.AddElem("Amount", to_string(amountObj.getAmount()));
	xml.OutOfElem();
	xml.Save("expenses.xml");
	cout << "New expense added.";


}
