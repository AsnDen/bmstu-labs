#include <iostream>
#include <string>

class BankAccount
{
    protected:
        int id;
        std::string owner;
        double balance;
    public:
        BankAccount( int i, std::string o, double b )
            : id{i}, owner{o}, balance{b} {}
        void deposit( double amount ) {
            balance += amount;
        }
        void withdraw( double amount ) {
            balance -= amount;
        }
        int getId() {
            return id;
        }
        std::string getOwner() {
            return owner;
        }
        double getBalance() {
            return balance;
        }
};

class SavingsAccount : public BankAccount
{
    private:
        double percent;
    public:
        SavingsAccount( int i, std::string o, double b, double p )
            : BankAccount( i, o, b ), percent{p} {}
        void PercentIncome() {
            balance *= percent;
        }
        double getPercent() {
            return percent;
        }
};

int main()
{
    BankAccount normal{1, "Pavel", 0};
    SavingsAccount savings{2, "Pavel", 0, 1.12};

    normal.deposit( 10000 );
    savings.deposit( 100000 );
    savings.PercentIncome();

    std::cout << normal.getBalance() << '\n';
    std::cout << savings.getBalance() << '\n';

    savings.withdraw( 10000 );

    std::cout << savings.getBalance() << '\n';

    return 0;
}
