class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        using ll = long long;
        vector<ll> sum(n),suffix(n),prefix(n);
        sum[0] = prices[0];
        prefix[0] = prices[0] * strategy[0];
        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i - 1] + prices[i] * strategy[i];
            sum[i] = sum[i - 1] + prices[i];
        }
        suffix[n - 1] = prices[n - 1] * strategy[n - 1];
        for(int i = n - 2;i >= 0;i--){
            suffix[i] = suffix[i + 1] + prices[i] * strategy[i];
        }
        ll maxv = LLONG_MIN;
        maxv = max(maxv,prefix[n - 1]);
        for(int i = 0;i + k <= n;i++){
            int j = i + k - 1;
            ll left = (i == 0) ? 0 : prefix[i - 1];
            ll right = (j == n - 1) ? 0 : suffix[j + 1];
            ll extra = sum[j] - sum[i + (k / 2) - 1];
            maxv = max(maxv,left + right + extra);
        }
        return maxv;
    }
};