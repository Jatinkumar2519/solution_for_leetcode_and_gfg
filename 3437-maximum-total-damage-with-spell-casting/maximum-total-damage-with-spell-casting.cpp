class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        using ll = long long;
        unordered_map<int,int> map;
        for(int& num : power){
            map[num]++;
        }
        vector<int> vals;
        for(auto& [num,_] : map) vals.push_back(num);
        sort(vals.begin(),vals.end());
        int n = vals.size();
        vector<ll> dp(n,0);
        dp[0] = (ll)vals[0] * map[vals[0]];
        for(int i = 1;i < n;i++){
            ll include = vals[i] * map[vals[i]];
            int j = i - 1;
            while(j >= 0 && vals[i] - vals[j] < 3) j--;
            if(j >= 0) include += dp[j];
            dp[i] = max(dp[i - 1],include);
        }
        return dp[n - 1];
    }
};