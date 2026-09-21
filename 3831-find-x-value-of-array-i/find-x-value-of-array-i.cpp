class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0),dp(k,0);

        for(int num : nums){

            vector<long long> ndp(k,0);
            ndp[num % k]++;

            for(int x = 0;x < k;x++){
                ndp[(x * 1LL * num) % k] += dp[x];
            }

            for(int x = 0;x < k;x++){
                result[x] += ndp[x];
            }

            dp = ndp;
        }
        return result;  
    }
};