
#include "HomeBudget.h"
#include <windows.h>
#include <algorithm>
#include <map>


namespace std {




    void HomeBudget::menu(UsersFile &usersFile) {

        int selection, balancePeriod;


        vector<Income> incomesVect;
        vector<Expense> expensesVect;
        HomeBudget homeBudget;

        while (true) {

            system("cls");

            cout << endl;

            cout << "1. Add new income" << endl;

            cout << "2. Add new expense" << endl;

            cout << "3. Balance from the current month" << endl;

            cout << "4. Balance from the last month" << endl;

            cout << "5. Balance from the specified month" << endl;

            cout << "6. Change password" << endl;

            cout << "9. End of program" << endl;

            cin >> selection;
            cin.ignore();


            switch (selection) {

                case 1:

                    incomes.addNewIncome(incomesVect, usersFile);

                    break;

                case 2:

                    expenses.addNewExpense(expensesVect, usersFile);


                    break;

                case 3:
                    balancePeriod = 1;
                    homeBudget.showBalance(usersFile, balancePeriod);

                    break;

                case 4:
                    balancePeriod = 2;
                    homeBudget.showBalance(usersFile, balancePeriod);

                    break;

                case 5:
                    balancePeriod = 3;
                    homeBudget.showBalance(usersFile, balancePeriod);
                    break;

                case 6:
                    usersFile.changeLoginPassword();

                    break;

                case 9:

                    exit(0);

            }

        }
    }

    vector<Income> HomeBudget::selectByMonthIncome(Incomes &incomes, int &balancePeriod) {
        vector<Income> selectByMonthIncome;



        if (balancePeriod == 3) {
            cout << "Set the initial date of interesting you period year-month-day: " << endl;
            this->dateObj.setDateBegin(dateObj.dateChosenByTheUser());
            this->dateObj.setDateBeginInt();

            cout << "Set the final date of interesting you period year-month-day: " << endl;
            this->dateObj.setDateEnd(dateObj.dateChosenByTheUser());
            this->dateObj.setDateEndInt();

        }

        for (int i = 0; i < incomes.getIncomesVect().size(); i++) {

            vector<Income> temp = incomes.getIncomesVect();

            int dateInt = temp[i].getDateObj().dataConversionToInt();

            SYSTEMTIME st;
            GetLocalTime(&st);

            map<int, string> previousMonth;
            previousMonth[0] = to_string(st.wYear - 1) + "12";
            previousMonth[1] = to_string(st.wYear - 1) + "12";
            previousMonth[2] = to_string(st.wYear) + "01";
            previousMonth[3] = to_string(st.wYear) + "02";
            previousMonth[4] = to_string(st.wYear) + "03";
            previousMonth[5] = to_string(st.wYear) + "04";
            previousMonth[6] = to_string(st.wYear) + "05";
            previousMonth[7] = to_string(st.wYear) + "06";
            previousMonth[8] = to_string(st.wYear) + "07";
            previousMonth[9] = to_string(st.wYear) + "08";
            previousMonth[10] = to_string(st.wYear) + "09";
            previousMonth[11] = to_string(st.wYear) + "10";
            previousMonth[12] = to_string(st.wYear) + "11";


            switch (balancePeriod) {

                case 1: {
                    string currentYearAndMonth;
                    if(st.wMonth<10)
                         currentYearAndMonth = to_string(st.wYear) +"0"+ to_string(st.wMonth);
                    else
                         currentYearAndMonth = to_string(st.wYear) + to_string(st.wMonth);

                    string date = to_string(dateInt);
                    if (date.find(currentYearAndMonth) == 0)
                        selectByMonthIncome.push_back(temp[i]);
                    break;
                }
                case 2: {
                    string date = to_string(dateInt);
                    if (date.find(previousMonth[st.wMonth]) == 0)
                        selectByMonthIncome.push_back(temp[i]);
                    break;
                }
                case 3: {
                    if (this->dateObj.getDateBeginInt() <= temp[i].getDateObj().dataConversionToInt() &&
                       this->dateObj.getDateEndInt() >= temp[i].getDateObj().dataConversionToInt())
                        selectByMonthIncome.push_back(temp[i]);
                    break;

                }
            }
        }
        return selectByMonthIncome;
    }


    vector<Expense> HomeBudget::selectByMonthExpense(Expenses &expenses, int &balancePeriod) {
        vector<Expense> selectByMonthExpense;



        for (int i = 0; i < expenses.getExpensesVect().size(); i++) {

            vector<Expense> temp = expenses.getExpensesVect();

            int dateInt = temp[i].getDateObj().dataConversionToInt();

            SYSTEMTIME st;
            GetLocalTime(&st);

            map<int, string> previousMonth;
            previousMonth[0] = to_string(st.wYear - 1) + "12";
            previousMonth[1] = to_string(st.wYear - 1) + "12";
            previousMonth[2] = to_string(st.wYear) + "01";
            previousMonth[3] = to_string(st.wYear) + "02";
            previousMonth[4] = to_string(st.wYear) + "03";
            previousMonth[5] = to_string(st.wYear) + "04";
            previousMonth[6] = to_string(st.wYear) + "05";
            previousMonth[7] = to_string(st.wYear) + "06";
            previousMonth[8] = to_string(st.wYear) + "07";
            previousMonth[9] = to_string(st.wYear) + "08";
            previousMonth[10] = to_string(st.wYear) + "09 ";
            previousMonth[11] = to_string(st.wYear) + "10";
            previousMonth[12] = to_string(st.wYear) + "11";


            switch (balancePeriod) {

                case 1: {
                    string currentYearAndMonth;
                    if(st.wMonth<10)
                        currentYearAndMonth = to_string(st.wYear) +"0"+ to_string(st.wMonth);
                    else
                        currentYearAndMonth = to_string(st.wYear) + to_string(st.wMonth);
                    string date = to_string(dateInt);
                    if (date.find(currentYearAndMonth) == 0)
                        selectByMonthExpense.push_back(temp[i]);

                    break;
                }
                case 2: {
                    string date = to_string(dateInt);
                    if (date.find(previousMonth[st.wMonth]) == 0)
                        selectByMonthExpense.push_back(temp[i]);
                    break;
                }
                case 3: {


                    if (this->dateObj.getDateBeginInt() <= temp[i].getDateObj().dataConversionToInt() &&
                            this->dateObj.getDateEndInt() >= temp[i].getDateObj().dataConversionToInt())
                        selectByMonthExpense.push_back(temp[i]);
                    break;

                }
            }
        }
        return selectByMonthExpense;
    }

    void HomeBudget::showBalance(UsersFile &usersFile, int &balancePeriod) {

        vector<Income> incomesVect;
        vector<Expense> expensesVect;
        Incomes incomes;
        Expenses expenses;

        incomes.loadIncomesFromXmlToVector();
        expenses.loadExpensesFromXmlToVector();
        incomesVect = selectByMonthIncome(incomes, balancePeriod);
        expensesVect = selectByMonthExpense(expenses, balancePeriod);

        int totalIncome = 0, totalExpense = 0, balance = 0;

        cout << "List of incomes from current month" << endl;
        cout << endl;


        sort(incomesVect.begin(), incomesVect.end(), [](Income &left, Income &right) {
            return left.getDateObj().dataConversionToInt() > right.getDateObj().dataConversionToInt();
        });

        for (int i = 0; i < incomesVect.size(); i++) {

            if (incomesVect[i].getUserId() == usersFile.getLogUserId()) {

                totalIncome += incomesVect[i].getAmountObj().getAmount();
                cout << "Income number: " << i + 1 << " Date: " << incomesVect[i].getDateObj().getDate() << " Name: "
                     << incomesVect[i].getIncomeName()
                     << " Amount: " << incomesVect[i].getAmountObj().getAmount() << " PLN" << endl;

            }
        }

        cout << endl;
        cout << "List of expences from current month" << endl;
        cout << endl;

        sort(expensesVect.begin(), expensesVect.end(), [](Expense &left, Expense &right) {
            return left.getDateObj().dataConversionToInt() > right.getDateObj().dataConversionToInt();
        });

        for (int i = 0; i < expensesVect.size(); i++) {
            if (expensesVect[i].getUserId() == usersFile.getLogUserId()) {
                totalExpense += expensesVect[i].getAmountObj().getAmount();
                cout << "Income number: " << i + 1 << " Date: " << expensesVect[i].getDateObj().getDate() << " Name: "
                     << expensesVect[i].getExpenseName()
                     << " Amount: " << expensesVect[i].getAmountObj().getAmount() << " PLN" << endl;
            }
        }

        cout << endl;
        cout << "Monthly balance summary: " << endl;
        cout << endl;
        balance = totalIncome - totalExpense;
        cout << "Your total income is: " << totalIncome << endl;
        cout << "Your total expense is: " << totalExpense << endl;
        cout << "Your saldo for this month is: " << balance << endl;
        cout << endl;

    }


}
