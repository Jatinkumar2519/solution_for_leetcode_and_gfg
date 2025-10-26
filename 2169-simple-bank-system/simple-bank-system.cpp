class Bank {
public:
    using ll = long long;
    vector<ll> arr;
    Bank(vector<long long>& balance) {
        arr = balance;
    }
    bool isvalid(int id){
        return 1 <= id && id <= arr.size();
    }
    bool transfer(int account1, int account2, long long money) {
        if(!isvalid(account1) || !isvalid(account2)) return false;
        if(money > arr[account1 - 1]) return false;
        arr[account1 - 1] -= money;
        arr[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!isvalid(account)) return false;
        arr[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!isvalid(account)) return false;
        if(money > arr[account - 1]) return false;
        arr[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */