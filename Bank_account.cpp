#include "Bank_account.hpp"

int Bank_Account::Get_Account(std::string name , std::vector < Bank_Account > &database){

    int account_index {-1};

    for (int i = 0; i < database.size(); i++){
        if (database[i].account_name == name){
            account_index = i;
            break;
        }
    }

    return account_index;
}

bool Bank_Account::Create_Account(std::string name , unsigned int pin , std::vector < Bank_Account > &database ){
    
    Bank_Account add_to_database{name , pin };

    size_t initial_database_dimension {database.size()};

    int create_account_result = Get_Account(name , database);

    if(create_account_result == -1){
        database.push_back(add_to_database);
    }

    size_t final_database_dimension{database.size()};

    bool create_account_status = (final_database_dimension - initial_database_dimension == 1);

    std::cout << "<Account successfully created>" << std::endl;
    
    return create_account_status;
}

void Bank_Account::Display_Account_Information(std::string name , std::vector < Bank_Account > &database){

    for(int i = 0; i < database.size(); i++){

        std::cout << database[i].account_name << std::endl;
        std::cout << database[i].account_index_number << std::endl;
        std::cout << database[i].account_balance << std::endl;

    }

}

bool Bank_Account::Pin_Code_Verification(unsigned int index_number , int pin , std::vector < Bank_Account > &database){

    bool status;

    if (pin == database[index_number].account_pin){

        std::cout << "Welcome!" << std::endl;

        status = true;
    }
    
    else {
        std::cout << "Wrong pin number!" << std::endl;


        status = false;
    }

    return status;

}

bool Bank_Account::Deposit(double deposit_amount , unsigned int index_number , std::vector < Bank_Account > &database){

    database[index_number].account_balance += deposit_amount;
    
    std::cout << "Deposit Successfully!" << std::endl;

    return true;
}

bool Bank_Account::Withdraw(double withdraw_amount , unsigned int index_number , std::vector < Bank_Account > &database){

    bool status;

    if (withdraw_amount <= database[index_number].account_balance) {
        
        database[index_number].account_balance -= withdraw_amount;

        std::cout << "Withdraw Successfully!" << std::endl;

        status = true;

    }

    else {

        std::cout << "Withdraw Failed!" << std::endl;
        std::cout << "Please check your funds and try a different amount!" << std::endl;

        status = false;
    }
    
    return status;
    
}

bool Bank_Account::Transfer(double transfer_amount , unsigned sender_index_number ,  unsigned recipient_index_number , std::vector < Bank_Account > &database){
    
    bool status;

    if (transfer_amount <= database[sender_index_number].account_balance){

        database[recipient_index_number].account_balance += transfer_amount;
        
        std::cout << "Transfer completed!" << std::endl;

        status = true;
    }

    else{

        std::cout << "Please check your funds and try a different amount!" << std::endl;

        status = false;

    }
    
    return status;

}

bool Bank_Account::Delete_Account(unsigned int index_number , std::vector < Bank_Account > &database){

    bool status;

    if(index_number != -1){

        database.erase(database.begin() + index_number);
        status = true;
    }

    else {

        status = false;

    }

    return status;

}

    
