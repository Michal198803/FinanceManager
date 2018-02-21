
#include <iostream>
#include "Manager.h"
#include "Markup.h"
#include <windows.h>
#include <string>
#include <algorithm>
#include <map>


namespace std {

    string dataBegin,dataEnd;

    vector<Login> loadAllUsersFromFile(vector<Login> &logins) {
        Login login;
        CMarkup xml;

        xml.Load("users.xml");

        while (xml.FindElem("User")) {
            xml.IntoElem();

            xml.FindElem(MCD_T("UserId"));
            string iduser = MCD_T("UserId");
            int id = atoi(MCD_2PCSZ(xml.GetData()));
            login.setIdUser(id);
            xml.FindElem("Login");
            login.setLogin(xml.GetData());
            xml.FindElem("Password");
            login.setPassword(xml.GetData());
            xml.FindElem("Name");
            login.setName(xml.GetData());
            xml.FindElem("Surname");
            login.setSurname(xml.GetData());
            xml.OutOfElem();
            logins.push_back(login);
        }
        return logins;
    }


    string catchDateFromSystem() {

        string date;

        SYSTEMTIME st;
        GetLocalTime(&st);

        int day = st.wDay;
        int month = st.wMonth;
        int year = st.wYear;

        date = to_string(year) + to_string(month) + to_string(day);

        return date;
    }

    map<string, string> createMapWithNumberOfDaysInMonth(string &year) {

        map<string, string> daysValidation;

        int yearInt = atoi(year.c_str());
        if (yearInt % 4 == 0)
            daysValidation["2"] = "29";
        else
            daysValidation["2"] = "28";

        daysValidation["1"] = "31";
        daysValidation["3"] = "31";
        daysValidation["4"] = "30";
        daysValidation["5"] = "31";
        daysValidation["6"] = "30";
        daysValidation["7"] = "31";
        daysValidation["8"] = "31";
        daysValidation["9"] = "30";
        daysValidation["10"] = "31";
        daysValidation["11"] = "30";
        daysValidation["12"] = "31";

        return daysValidation;
    }

    string dateChosenByTheUser() {
        bool enterTheYear = false;
        bool enterTheMonth = false;
        bool enterTheDay = false;
        string year, year2, month, day, date, tempData;
        map<string, string> daysValidation = createMapWithNumberOfDaysInMonth(year2);
        string tabDate[3];
        int tabDateIndex = 0;
        SYSTEMTIME st;
        GetLocalTime(&st);
        char dateChar;

        cout << "Enter the date year-month-day:  ";
        cin.clear();
        cin.sync();

        getline(cin, date);
        cin.sync();

        for (int i = 0; i < date.size(); i++) {
            dateChar = date[i];
            if (dateChar != '-')
                tempData += dateChar;
            else {
                tabDate[tabDateIndex] = tempData;
                tempData = "";
                tabDateIndex++;
            }
        }
        tabDate[2] = tempData;
        tempData = "";
        year = tabDate[0];
        month = tabDate[1];
        day = tabDate[2];

        if (atoi(year.c_str()) >= 2000 && atoi(year.c_str()) <= st.wYear)
            enterTheYear = true;

        else

            cout << "Please insert year in ranger 2000-" << st.wYear << endl;


        if (atoi(month.c_str()) >= 1 && atoi(month.c_str()) <= 12)
            enterTheMonth = true;

        else
            cout << "Please insert month in range 1-12" << endl;


        if (atoi(day.c_str()) >= 1 && atoi(day.c_str()) <= atoi(daysValidation[month].c_str()))
            enterTheDay = true;
        else
            cout << "Please insert day in range 1-" << daysValidation[month] << endl;

        if (enterTheYear == false || enterTheMonth == false || enterTheDay == false)
            dateChosenByTheUser();
        else

            return date = year + month + day;

    }

    string setIncomeDate() {
        int selection = 0;
        string date;

        cout << "Select income date: " << endl;
        cout << "1.Current date " << endl;
        cout << "2.Date selsected by user " << endl;

        cin >> selection;
        cin.ignore();

        switch (selection) {

            case 1:
                date = catchDateFromSystem();
                break;

            case 2:
                date = dateChosenByTheUser();
        }
        return date;
    }


    string setExpenseDate() {
        int selection = 0;

        string year, month, day, date;
        map<string, string> daysValidation;
        cout << "Select expense date: " << endl;
        cout << "1.Current date " << endl;
        cout << "2.Date selsected by user " << endl;
        cin >> selection;
        cin.ignore();


        switch (selection) {

            case 1:
                date = catchDateFromSystem();
                break;

            case 2:
                date = dateChosenByTheUser();
                break;
        }
        return date;
    }


    void menu(int &numerIdZalogowanegoUsera) {

        int selection, balancePeriod;
        vector<Incomes> incomes;
        vector<Expenses> expenses;
        Manager manager;

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

                    manager.addNewIncome(numerIdZalogowanegoUsera);

                    break;

                case 2:

                    manager.addNewExpense(numerIdZalogowanegoUsera);

                    break;

                case 3:
                    balancePeriod = 1;
                    manager.showBalance(numerIdZalogowanegoUsera, balancePeriod);

                    break;

                case 4:
                    balancePeriod = 2;
                    manager.showBalance(numerIdZalogowanegoUsera, balancePeriod);

                    break;

                case 5:
                    balancePeriod = 3;
                    manager.showBalance(numerIdZalogowanegoUsera, balancePeriod);
                    break;

                case 6:
                    manager.changeLoginPassword(numerIdZalogowanegoUsera);

                    break;

                case 9:

                    exit(0);

            }

        }
    }


    vector<Incomes> loadAllIncomesFromXmlFile(vector<Incomes> &incomes) {

        Incomes income;
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
            int date = atoi(MCD_2PCSZ(xml.GetData()));
            income.setDate(date);
            xml.FindElem("Amount");
           float amount = atoi(MCD_2PCSZ(xml.GetData()));
            income.setAmount(amount);
            xml.OutOfElem();
            incomes.push_back(income);
        }
        return incomes;

    }

    void Manager::addNewIncome(int &numerIdZalogowanegoUsera) {
        int incomeIdInt;

        incomes = loadAllIncomesFromXmlFile(incomes);
        int incomeNumber = incomes.size();

        if (incomes.size() == 0)
            incomeIdInt = 1;
        else
            incomeIdInt = incomes[incomeNumber - 1].getIncomeId() + 1;

        CMarkup xml;

        string userId, incomeId, incomeName, incomeDate, incomeAmount;
        incomeId = to_string(incomeIdInt);
        userId = to_string(numerIdZalogowanegoUsera);
        cout << "Enter the income name: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, incomeName);
        incomeDate = setIncomeDate();
        cout << "Enter the income amount: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, incomeAmount);
        if(incomeAmount.find(',')) {
            replace(incomeAmount.begin(),incomeAmount.end(),',','.');
            puts(incomeAmount.c_str());
        }
        xml.Load("incomes.xml");
        xml.AddElem("Income");
        xml.IntoElem();
        xml.AddElem("UserId", userId);
        xml.AddElem("Id", incomeId);
        xml.AddElem("Name", incomeName);
        xml.AddElem("Date", incomeDate);
        xml.AddElem("Amount", incomeAmount);
        xml.OutOfElem();
        xml.Save("incomes.xml");
        cout << "New income added.";

        menu(numerIdZalogowanegoUsera);
    }


    vector<Expenses> loadAllExpensesFromXmlFile(vector<Expenses> &expenses) {

        Expenses expense;
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
            int date = atoi(MCD_2PCSZ(xml.GetData()));
            expense.setDate(date);
            xml.FindElem("Amount");
          float amount = atoi(MCD_2PCSZ(xml.GetData()));
            expense.setAmount(amount);
            xml.OutOfElem();
            expenses.push_back(expense);
        }
        return expenses;
    }

    void Manager::addNewExpense(int &numerIdZalogowanegoUsera) {


        int expenseIdInt;
        int expenseNumber = loadAllExpensesFromXmlFile(expenses).size();

        if (expenses.size() == 0)
            expenseIdInt = 1;
        else
            expenseIdInt = expenses[expenseNumber - 1].getExpenseId() + 1;


        CMarkup xml;

        string userId, expenseId, expenseName, expenseDate, expenseAmount;
        userId = to_string(numerIdZalogowanegoUsera);
        expenseId = to_string(expenseIdInt);

        cout << "Enter the expense name: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, expenseName);

        expenseDate = setExpenseDate();

        cout << "Enter the expense amount: " << endl;
        cin.clear();
        cin.sync();
        getline(cin, expenseAmount);
        if(expenseAmount.find(',')) {
            replace(expenseAmount.begin(),expenseAmount.end(),',','.');
            puts(expenseAmount.c_str());
        }
        xml.Load("expenses.xml");
        xml.AddElem("Expense");

        xml.IntoElem();
        xml.AddElem("UserId", userId);
        xml.AddElem("Id", expenseId);
        xml.AddElem("Name", expenseName);
        xml.AddElem("Date", expenseDate);
        xml.AddElem("Amount", expenseAmount);

        xml.OutOfElem();
        xml.Save("expenses.xml");

        cout << "New expense added.";

        menu(numerIdZalogowanegoUsera);

    }

    void Manager::logOn(int &numerIdZalogowanegoUsera) {

        Login login;

        string enteredLogin, enteredPassword;

        loadAllUsersFromFile(logins);


        cout << "Enter your login: " << endl;
        cin >> enteredLogin;


        for (int i = 0; i < logins.size(); i++) {
            if (logins[i].getLogin() == enteredLogin) {
                cout << "Enter your password: " << endl;
                cin >> enteredPassword;
                if (logins[i].getPassword() == enteredPassword) {
                    numerIdZalogowanegoUsera = logins[i].getIdUser();
                    menu(numerIdZalogowanegoUsera);
                }
            }
        }
    }

    void Manager::registration(int numerIdZalogowanegoUsera) {
        CMarkup xml;
        string password[2];
        string login;
        string name;
        string surname;
        int userIdInt;
        string userId;

        int usersQuantity = loadAllUsersFromFile(logins).size();


        if (usersQuantity == 0)
            userIdInt = 1;
        else
            userIdInt = logins[usersQuantity - 1].getIdUser() + 1;


        bool passwordCorrection = false;

        cout << "Insert your future login: ";
        cin >> login;
        while (passwordCorrection == false) {
            cout << "Insert your future password: ";
            cin >> password[0];
            cout << "Please insert password again to check correctness: ";
            cin >> password[1];
            if (password[0] == password[1]) {
                passwordCorrection = true;
            }
        }
        cout << "Insert your name: ";
        cin >> name;
        cout << "Insert your surname: ";
        cin >> surname;

        char string[10] = {0};


        userId += itoa(userIdInt, string, 10);

        xml.Load("users.xml");
        xml.AddElem("User");

        xml.IntoElem();
        xml.AddElem("UserId", userId);
        xml.AddElem("Login", login);
        xml.AddElem("Password", password[0]);
        xml.AddElem("Name", name);
        xml.AddElem("Surname", surname);
        xml.OutOfElem();
        xml.Save("users.xml");

    }

    vector<Incomes> selectUserDataFromIncomeXml(int &numerIdZalogowanegoUsera) {
        vector<Incomes> incomes;

        vector<Incomes> selectedIncomes;

        for (int i = 0; i < incomes.size(); i++) {

            if (incomes[i].getUserId() == numerIdZalogowanegoUsera)
                selectedIncomes.push_back(incomes[i]);
        }

        return selectedIncomes;
    }

    vector<Expenses> selectUserDataFromExpenseXml(int &numerIdZalogowanegoUsera) {

        vector<Expenses> expenses;
        vector<Expenses> selectedExpenses;


        for (int i = 0; i < expenses.size(); i++) {

            if (expenses[i].getUserId() == numerIdZalogowanegoUsera)
                selectedExpenses.push_back(expenses[i]);
        }

        return selectedExpenses;
    }




    vector<Incomes> selectByMonthIncome(vector<Incomes> &incomes, int &balancePeriod) {
        vector<Incomes> selectByMonthIncome;
        loadAllIncomesFromXmlFile(incomes);

        int dateBeginInt,dateEndInt;
        if (balancePeriod == 3) {
            cout<<"Set the initial date of interesting you period year-month-day: "<<endl;
            dataBegin=dateChosenByTheUser();
            cout<<"Set the final date of interesting you period year-month-day: "<<endl;
            dataEnd=dateChosenByTheUser();
        }

        for (int i = 0; i < incomes.size(); i++) {
          int dateInt = incomes[i].getDate();

            SYSTEMTIME st;
            GetLocalTime(&st);

            map<int, string> previousMonth;
            previousMonth[0] = to_string(st.wYear - 1) + "12";
            previousMonth[1] = to_string(st.wYear - 1) + "12";
            previousMonth[2] = to_string(st.wYear) + "1";
            previousMonth[3] = to_string(st.wYear) + "2";
            previousMonth[4] = to_string(st.wYear) + "3";
            previousMonth[5] = to_string(st.wYear) + "4";
            previousMonth[6] = to_string(st.wYear) + "5";
            previousMonth[7] = to_string(st.wYear) + "6";
            previousMonth[8] = to_string(st.wYear) + "7";
            previousMonth[9] = to_string(st.wYear) + "8";
            previousMonth[10] = to_string(st.wYear) + "9";
            previousMonth[11] = to_string(st.wYear) + "10";
            previousMonth[12] = to_string(st.wYear) + "11";


            switch (balancePeriod) {

                case 1: {
                    string currentYearAndMont = to_string(st.wYear) + to_string(st.wMonth);
                       string date=to_string(dateInt);
                    if (date.find(currentYearAndMont) == 0)
                        selectByMonthIncome.push_back(incomes[i]);
                    break;
                }
                case 2: {
                    string date=to_string(dateInt);
                    if (date.find(previousMonth[st.wMonth]) == 0)
                        selectByMonthIncome.push_back(incomes[i]);
                    break;
                }
                case 3: {
                    if(dateBeginInt <= incomes[i].getDate()||dateEndInt>=incomes[i].getDate())
                        selectByMonthIncome.push_back(incomes[i]);
                    break;
                    break;
                }
            }
        }
        return selectByMonthIncome;
    }

    vector<Expenses> selectByMonthExpense(vector<Expenses> &expenses, int &balancePeriod) {
        vector<Expenses> selectByMonthExpense;
        loadAllExpensesFromXmlFile(expenses);

        int dateBeginInt,dateEndInt;
        if (balancePeriod == 3) {



            dateBeginInt=atoi(dataBegin.c_str());
            dateEndInt=atoi(dataEnd.c_str());

        }
        for (int i = 0; i < expenses.size(); i++) {
           int dateInt = expenses[i].getDate();

            SYSTEMTIME st;
            GetLocalTime(&st);

            map<int, string> previousMonth;
            previousMonth[0] = to_string(st.wYear - 1) + "12";
            previousMonth[1] = to_string(st.wYear - 1) + "12";
            previousMonth[2] = to_string(st.wYear) + "1";
            previousMonth[3] = to_string(st.wYear) + "2";
            previousMonth[4] = to_string(st.wYear) + "3";
            previousMonth[5] = to_string(st.wYear) + "4";
            previousMonth[6] = to_string(st.wYear) + "5";
            previousMonth[7] = to_string(st.wYear) + "6";
            previousMonth[8] = to_string(st.wYear) + "7";
            previousMonth[9] = to_string(st.wYear) + "8";
            previousMonth[10] = to_string(st.wYear) + "9";
            previousMonth[11] = to_string(st.wYear) + "10";
            previousMonth[12] = to_string(st.wYear) + "11";


            switch (balancePeriod) {

                case 1: {
                    string currentYearAndMont = to_string(st.wYear) + to_string(st.wMonth);
                    string date=to_string(dateInt);
                    if (date.find(currentYearAndMont) == 0)
                        selectByMonthExpense.push_back(expenses[i]);
                    break;
                }
                case 2: {
                    string date=to_string(dateInt);
                    if (date.find(previousMonth[st.wMonth]) == 0)
                        selectByMonthExpense.push_back(expenses[i]);
                    break;
                }
                case 3: {

                    if(dateBeginInt <= expenses[i].getDate()||dateEndInt>=expenses[i].getDate())
                        selectByMonthExpense.push_back(expenses[i]);
                    break;
                }
            }
        }
        return selectByMonthExpense;
    }

    void Manager::showBalance(int &numerIdZalogowanegoUsera, int &balancePeriod) {

        int totalIncome, totalExpense, balance;

        vector<Incomes> selectedIncomes = selectUserDataFromIncomeXml(numerIdZalogowanegoUsera);
        selectedIncomes = selectByMonthIncome(selectedIncomes, balancePeriod);
        vector<Expenses> selectedExpenses = selectUserDataFromExpenseXml(numerIdZalogowanegoUsera);
        selectedExpenses = selectByMonthExpense(selectedExpenses, balancePeriod);


        cout << "List of incomes from current month" << endl;
        cout << endl;

        sort(selectedIncomes.begin(), selectedIncomes.end(), [](const Incomes &left, const Incomes &right) {
            return left.getDate() < right.getDate();
        });

        for (int i = 0; i < selectedIncomes.size(); i++) {
            totalIncome += selectedIncomes[i].getAmount();
            cout << " Income number: " << i + 1 << " Date: " << selectedIncomes[i].getDate() << " Name: "
                 << selectedIncomes[i].getIncomeName()
                 << " Amount: " << selectedIncomes[i].getAmount() << " PLN" << endl;
        }

        cout << endl;
        cout << "List of expences from current month" << endl;
        cout << endl;
        sort(selectedExpenses.begin(), selectedExpenses.end(), [](const Expenses &left, const Expenses &right) {
            return left.getDate() < right.getDate();
        });

        for (int i = 0; i < selectedExpenses.size(); i++) {
            totalExpense += selectedExpenses[i].getAmount();
            cout << "Income number: " << i + 1 << " Date: " << selectedExpenses[i].getDate() << " Name: "
                 << selectedExpenses[i].getExpenseName()
                 << " Amount: " << selectedExpenses[i].getAmount() << " PLN" << endl;;
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


    void Manager::changeLoginPassword(int &numerIdZalogowanegoUsera) {
        Login login;
        CMarkup xml;
        string enteredPassword;

        vector<Login> loginsTemp = loadAllUsersFromFile(logins);
        for (int i = 0; i < logins.size(); i++) {

            if (logins[i].getIdUser() == numerIdZalogowanegoUsera) {
                cout << "Set the new password" << endl;
                getline(cin, enteredPassword);
                logins[i].setPassword(enteredPassword.c_str());
            }

        }

        remove("users.xml");


        for (int i = 0; i < logins.size(); i++) {
            xml.Load("users.xml");
            xml.AddElem("User");
            xml.IntoElem();
            xml.AddElem("UserId", logins[i].getIdUser());
            xml.AddElem("Login", logins[i].getLogin());
            xml.AddElem("Password", logins[i].getPassword());
            xml.AddElem("Name", logins[i].getName());
            xml.AddElem("Surname", logins[i].getSurname());
            xml.OutOfElem();
            xml.Save("users.xml");
        }

        cout << "Password changed successfully" << endl;
        logOn(numerIdZalogowanegoUsera);

    }

}