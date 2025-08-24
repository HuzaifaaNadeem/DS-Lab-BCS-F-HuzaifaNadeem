#include <iostream>
using namespace std;

class BankAccount {
	private:
	    double balance;
	
	public:
	    
	    BankAccount() {
	        balance = 0.0;
	    }
	
	    BankAccount(double initialBalance) {
	        balance = initialBalance;
	    }
	
	    BankAccount(const BankAccount &acc) {
	        balance = acc.balance;
	    }

	    void deposit(double amount) {
	        balance += amount;
	    }
	 
	    void withdraw(double amount) {
	        if (amount <= balance) {
	            balance -= amount;
	        } else {
	            cout << "Amount can't be withdrawn (Insufficient Funds) !" << endl;
	        }
	    }
	
	    double getBalance() const {
	        return balance;
	    }
};


int main() {
    
    BankAccount account1;
    cout << "Balance of account1: $" << account1.getBalance() << endl;
    BankAccount account2(1000.0);
    cout << "Balance of account2: $" << account2.getBalance() << endl;
    BankAccount account3(account2);  
    account3.withdraw(200.0);
    cout << "Balance of account3: $" << account3.getBalance() << endl;
    cout << "Balance of account2: $" << account2.getBalance() << endl;

    return 0;
}

