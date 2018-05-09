

#ifndef FINANCEMANAGET_USERS_H
#define FINANCEMANAGET_USERS_H

#include<vector>
#include"UsersFile.h"
#include"User.h"
class Users {


private:
    vector <User> logins;
public:
 vector<User> getLogins() ;

    void setLogins(vector<User> logins);


};


#endif //FINANCEMANAGET_USERS_H
