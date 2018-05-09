

#ifndef FINANCEMANAGET_USERS_H
#define FINANCEMANAGET_USERS_H

#include"User.h"
#include <vector>

class UsersFile {

private:
    vector<User> usersVect;
    int logUserId;
public:
    int getLogUserId();

    void setLogUserId(int logUserId);

public:
    vector<User> getUsersVect();

    void setUsersVect(vector<User> usersVect);

    void registration();

    void logOn();

    void changeLoginPassword();
};


#endif //FINANCEMANAGET_USERS_H
