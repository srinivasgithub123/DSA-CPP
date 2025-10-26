class Bank {
    vector<long long> balance;  // store balances
public:
    Bank(vector<long long>& balances) {
        balance = balances;
    }

    bool transfer(int account1, int account2, long long money) {
        if ((account1 >= 1 && account1 <= (int)balance.size()) &&
            (account2 >= 1 && account2 <= (int)balance.size()) &&
            (balance[account1 - 1] >= money)) {

            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        } else {
            return false;
        }
    }

    bool deposit(int account, long long money) {
        if(account >= 1 && account <= (int)balance.size()){
            balance[account - 1] += money;
            return true;
        } else {
            return false;
        }
    }

    bool withdraw(int account, long long money) {
        if ((account >= 1 && account <= (int)balance.size()) && (balance[account - 1] >= money)) { 
            balance[account - 1] -= money; 
            return true;
        } else {
            return false; 
        }
    }
};
