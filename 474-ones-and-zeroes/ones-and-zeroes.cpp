class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<pair<int,int>> arr;
        for(auto& str : strs){
            int one = 0,zero = 0;
            for(auto& ch : str){
                one += (ch == '1') ? 1 : 0;
                zero += (ch == '0') ? 1 : 0;
            }
            arr.push_back({zero,one});
        }

        int sum_0 = 0;
        int sum_1 = 0;
        static int dp[101][101][601];
        memset(dp,-1,sizeof(dp));
        function<int(int)> solve = [&](int curr)->int{
            if(curr == len) return 0;
            if(dp[sum_0][sum_1][curr] != -1) return dp[sum_0][sum_1][curr];
            int maxlen = solve(curr + 1);
            if(sum_0 + arr[curr].first <= m && sum_1 + arr[curr].second <= n){
                sum_0 += arr[curr].first;
                sum_1 += arr[curr].second;
                maxlen = max(maxlen,1 + solve(curr + 1));
                sum_0 -= arr[curr].first;
                sum_1 -= arr[curr].second;
            }
            return dp[sum_0][sum_1][curr] = maxlen;
        };
        return solve(0);
    }
};