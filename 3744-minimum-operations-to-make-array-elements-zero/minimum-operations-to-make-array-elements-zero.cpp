class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        using ll = long long;
        function<ll(int)> getCount = [&](int num) -> ll {
            int len = 1;
            ll count = 0;
            int base = 1;
            while(base <= num){
                count += 1LL * (len + 1)/2 * (min((base << 1) - 1,num) - base + 1);
                len++;base <<= 1;
            }
            return count;
        };
        ll count = 0;
        for(auto& query : queries){
            count += (getCount(query[1]) - getCount(query[0] - 1) + 1)/2;
        }
        return count;
    }
};