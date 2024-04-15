#ifndef BANK_ACCOUNT_HPP
#define BANK_ACCOUNT_HPP

#include <iostream>
#include <vector>
#include <string>

class Bank_Account{

public:

    std::string account_name;
    unsigned int account_pin {0};
    unsigned int account_index_number {0};
    double account_balance {0};

    int Get_Account(std::string name , std::vector < Bank_Account > &database);
    bool Create_Account(std::string name , unsigned int pin , std::vector < Bank_Account > &database );
    bool Pin_Code_Verification(unsigned int index_number , int pin , std::vector < Bank_Account > &database);
    bool Deposit(double deposit_amount , unsigned int index_number , std::vector < Bank_Account > &database);
    bool Withdraw(double withdraw_amount ,  unsigned int index_number , std::vector < Bank_Account > &database);
    bool Transfer(double transfer_amount , unsigned int sender_index_number ,  unsigned int recipient_index_number , std::vector < Bank_Account > &database);
    bool Delete_Account(unsigned int index_number , std::vector < Bank_Account > &database);
    void Display_Account_Information(std::string name , std::vector < Bank_Account >& database);

};

#endif