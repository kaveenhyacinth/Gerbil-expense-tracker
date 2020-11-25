#ifndef ACCOUNTCONTROLLER_H
#define ACCOUNTCONTROLLER_H

#include "account.h"

class AccountController
{
public:
    AccountController();

public:
    void CreateAccount(Account);
    void DeleteAccount(int);
};

#endif // ACCOUNTCONTROLLER_H
