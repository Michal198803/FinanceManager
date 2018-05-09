#include <windows.h>
#include <map>
#include "Date.h"
#include <algorithm>

using namespace std;

string Date::getDate() {

    return date;
}

void Date::setDate(string date) {

    this->date = date;
}

int Date::dataConversionToInt() {
    char dateChar;
    string tempData;


    for (int i = 0; i < date.size(); i++) {
        dateChar = date[i];
        if (dateChar != '-')
            tempData += dateChar;
    }

    int dateInInt = atoi(tempData.c_str());

    return dateInInt;
}

bool Date::dateValidation(string date) {

    for (int i = 0; i < date.size(); i++) {


        if (date[i] != '0' && date[i] != '1' && date[i] != '2'
            && date[i] != '3' && date[i] != '4'
            && date[i] != '5' && date[i] != '6'
            && date[i] != '7' && date[i] != '8'
            && date[i] != '9' && date[i] != '-'
                ) {
            cout << "Date should contains digits" << endl;
            return false;
        }
    }

    return true;;
}

string Date::catchDateFromSystem() {
    string dayStr, monthStr;

    SYSTEMTIME st;
    GetLocalTime(&st);
    int day = st.wDay;
    if (st.wDay < 10)
        dayStr = "0" + to_string(day);
    else
        dayStr = to_string(day);
    int month = st.wMonth;
    if (st.wMonth < 10)
        monthStr = "0" + to_string(month);
    else
        monthStr = to_string(month);

    int year = st.wYear;

    date = to_string(year) + "-" + monthStr + "-" + dayStr;

    return date;
}

map<string, string> createMapWithNumberOfDaysInMonth(string &year) {

    map<string, string> daysValidation;

    int yearInt = atoi(year.c_str());
    if (yearInt % 4 == 0)
        daysValidation["2"] = "29";
    else
        daysValidation["2"] = "28";

    daysValidation["01"] = "31";
    daysValidation["03"] = "31";
    daysValidation["04"] = "30";
    daysValidation["05"] = "31";
    daysValidation["06"] = "30";
    daysValidation["07"] = "31";
    daysValidation["08"] = "31";
    daysValidation["09"] = "30";
    daysValidation["10"] = "31";
    daysValidation["11"] = "30";
    daysValidation["12"] = "31";

    return daysValidation;
}

string Date::dateChosenByTheUser() {
    bool enterTheYear = false;
    bool enterTheMonth = false;
    bool enterTheDay = false;
    char dateChar;

    cout << "Enter the date year-month-day:  ";
    cin.clear();
    cin.sync();

    getline(cin, this->date);
    cin.sync();

    string year, year2, month, day, tempData;
    map<string, string> daysValidation = createMapWithNumberOfDaysInMonth(year2);
    string tabDate[3];
    int tabDateIndex = 0;
    SYSTEMTIME st;
    GetLocalTime(&st);
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
        cout << "Please insert month in range 01-12" << endl;

    if (atoi(day.c_str()) >= 1 && atoi(day.c_str()) <= atoi(daysValidation[month].c_str())) {

        enterTheDay = true;
    } else
        cout << "Please insert day in range 01-" << daysValidation[month] << endl;

    if (enterTheYear == false || enterTheMonth == false || enterTheDay == false)
        dateChosenByTheUser();

    return date = year + "-" + month + "-" + day;
}

string Date::enterTheDate(string date) {

    int selection = 0;

    cout << "Select income date: " << endl;
    cout << "1.Current date " << endl;
    cout << "2.Date selsected by user " << endl;

    cin >> selection;
    cin.ignore();

    switch (selection) {

        case 1:

            date = catchDateFromSystem();
            break;

        case 2: {

            string dateString = dateChosenByTheUser();

            if (this->dateValidation(dateString) == false)
                this->enterTheDate(date);
        }
    }

    return this->date;
}

void Date::setDateBegin(const string &dateBegin) {
    Date::dateBegin = dateBegin;
}




void Date::setDateEnd(const string &dateEnd) {
    Date::dateEnd = dateEnd;
}

int Date::getDateBeginInt() const {
    return dateBeginInt;
}

void Date::setDateBeginInt() {

    this->dateBegin.erase(std::remove(this->dateBegin.begin(), this->dateBegin.end(), '-'), this->dateBegin.end());

    Date::dateBeginInt = atoi(dateBegin.c_str());
}

int Date::getDateEndInt() const {
    return dateEndInt;
}

void Date::setDateEndInt() {

    this->dateEnd.erase(std::remove(this->dateEnd.begin(), this->dateEnd.end(), '-'), this->dateEnd.end());

    Date::dateEndInt = atoi(dateEnd.c_str());


}



