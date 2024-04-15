#include "Bank_account.hpp"

int main(){

    std::vector < Bank_Account > database;

    unsigned int account_index_number_main;
    unsigned int account_pin_main;
    unsigned int amount;
    unsigned int enter_choice;

    std::string account_name_main;

    do {

        std::cout << "GS Personal Project" << std::endl;
        std::cout << "1. Create a new account" << std::endl;
        std::cout << "2. Display account information" << std::endl;
        std::cout << "3. Deposit funds" << std::endl;
        std::cout << "4. Withdraw funds" << std::endl;
        std::cout << "5. Delete account" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: " << std::endl;
        std::cin >> enter_choice;

        switch (enter_choice) {

            case 1: {
//1. Create a new account
                std::cout << "Enter ccount holder name: " << std::endl;
                //std::cin >> account_name_main;
                std::cin.ignore();
                getline(std::cin , account_name_main);

                std::cout << "Create a PIN: " << std::endl;
                std::cin >> account_pin_main;

                Bank_Account new_account;
                new_account.Create_Account(account_name_main, account_pin_main, database);
                break;

            }
//2. Display account information
            case 2: {

                    std::cout << "Enter account name: ";
                    std::cin >> account_name_main;

                    database[account_index_number_main].Display_Account_Information(account_name_main , database);

                    break;
            }
//3. Deposit funds
            case 3: {

                std::cout << "Enter account ID: ";
                std::cin >> account_index_number_main;

                std::cout << "Enter deposit amount: ";
                std::cin >> amount;

                database[account_index_number_main].Deposit(amount, account_index_number_main, database);

                break;

            }
//4. Withdraw funds
            case 4: {

                std::cout << "Enter account index number: ";
                std::cin >> account_index_number_main;

                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;

                database[account_index_number_main].Withdraw(amount, account_index_number_main, database);

                break;

            }
//5. Delete account          
            case 5: {

                std::cout << "Enter account index number: ";
                std::cin >> account_index_number_main;

                database[account_index_number_main].Delete_Account(account_index_number_main, database);

                break;

            }
//6. Exit
            case 6:

                std::cout << "Exiting..." << std::endl;

                break;

            default:

                std::cout << "Invalid choice. Please enter a number between 1 and 6." << std::endl;
                break;
                
        }

    } while (enter_choice != 6);

    return 0;
}
