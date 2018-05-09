
#include <iostream>

#ifndef FINANCEMANAGET_DATE_H
#define FINANCEMANAGET_DATE_H

 using namespace std;
 extern const struct dsm_config DEFAULT_DSM_CONFIG;
class Date {

private:
string date,dateBegin,dateEnd;
public:
    void setDateBegin(const string &dateBegin);



    void setDateEnd(const string &dateEnd);

    int getDateBeginInt() const;

    void setDateBeginInt();

    int getDateEndInt() const;

    void setDateEndInt();

private:
    int dateBeginInt,dateEndInt;
public:
    string getDate() ;
    string dateChosenByTheUser();
    void setDate(string date);
bool dateValidation(string date);
    int dataConversionToInt();
    string catchDateFromSystem();
    string enterTheDate(string ate);
};


#endif //FINANCEMANAGET_DATE_H
