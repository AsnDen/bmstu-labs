#include <iostream>
#include <string>
#include <vector>

struct BankAccount {
    size_t id{};
    long double balance{};
    std::string name{};
};

void showMenu()
{
    std::cout << "--------------------\n"
              << "Choose an option:\n"
                 "1. Create an accout\n"
                 "2. Make a deposit\n"
                 "3. Withdraw money\n"
                 "4. Show info about account\n"
                 "5. Exit\n";
}

void addAccout( std::vector<BankAccount> &accounts )
{
    BankAccount new_acc{};
    std::cout << "Enter account's id and owner's name\n";
    std::cin >> new_acc.id >> new_acc.name;

    for( BankAccount acc : accounts ) {
        if( acc.id == new_acc.id ) {
            std::cout << "Account with such id already exists\n";
            return;
        }
    }
    accounts.push_back( new_acc );
}

void makeDeposit( std::vector<BankAccount> &accounts )
{
    std::cout << "Enter account's id and deposit value\n";
    size_t id{};
    long double depo{};
    std::cin >> id >> depo;

    for( BankAccount acc : accounts ) {
        if( acc.id == id ) {
            acc.balance += depo;
            return;
        }
    }

    std::cout << "There is no account with id " << id << '\n';
}

void makeWithdraw( std::vector<BankAccount> &accounts )
{
    std::cout << "Enter account's id and withdraw value\n";
    size_t id{};
    long double withdraw{};
    std::cin >> id >> withdraw;

    for( BankAccount acc : accounts ) {
        if( acc.id == id && acc.balance > withdraw ) {
            acc.balance -= withdraw;
            return;
        }
    }

    std::cout << "There is no account with id " << id
              << " or there is not anought money" << '\n';
}

void showInfoAboutAccount( std::vector<BankAccount> &accounts )
{
    std::cout << "Enter account's id\n";
    size_t id{};
    std::cin >> id;

    for( BankAccount acc : accounts ) {
        if( acc.id == id ) {
            std::cout << "Id: " << acc.id << '\n'
                      << "Balance: " << acc.balance << '\n'
                      << "Owner: " << acc.name << '\n';
            return;
        }
    }

    std::cout << "There is no account with id " << id << '\n';
}

int main()
{
    bool programWorking {true};
    std::vector<BankAccount> accounts{};
    while( programWorking ) {
        showMenu();
        short unsigned int inp{};
        std::cin >> inp;
        switch( inp ) {
            case 1:
                addAccout( accounts );
                break;
            case 2:
                makeDeposit( accounts );
                break;
            case 3:
                makeWithdraw( accounts );
                break;
            case 4:
                showInfoAboutAccount( accounts );
                break;
            case 5:
                programWorking = false;
                break;

            default:
                break;
        }
    }

    return 0;
}
