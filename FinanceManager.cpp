
#include <iostream>
#include <vector>
#include "HomeBudget.h"
#include "User.h"
using namespace std;

int main() {
    int selection;


    string loginInserted;;

    vector<User> logins;
    vector<Expense> expenses;
    vector<Income> incomes;
    User login;

    UsersFile userFile;
    while (true) {

        cout << endl;
        cout << "1.Login" << endl << endl;
        cout << "2.Registration" << endl << endl;
        cout << "3.End of the program" << endl << endl;

        cin >> selection;

        switch (selection) {

            case 1:

              userFile.logOn();

                break;
            case 2:

                userFile.registration();

                break;
            case 3:
                exit(0);

        }
    }
}
