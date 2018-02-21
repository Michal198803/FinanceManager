
#include <iostream>
#include <vector>
#include "Login.h"
#include "Manager.h"
using namespace std;

int main() {
    int selection;
int numerIdZalogowanegoUsera;

    string loginInserted;;

    vector<Login> logins;
    vector<Expenses> expenses;
    vector<Incomes> incomes;
    Login login;
    Manager user;

    while (true) {

        cout << endl;
        cout << "1.Login" << endl << endl;
        cout << "2.Registration" << endl << endl;
        cout << "3.End of the program" << endl << endl;

        cin >> selection;

        switch (selection) {

            case 1:

                user.logOn(numerIdZalogowanegoUsera);

                break;
            case 2:

                user.registration(numerIdZalogowanegoUsera);

                break;
            case 3:
                exit(0);

        }
    }
}
