// # define int long long
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        dp[1][1] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n - i + 1;j++){
                if(i == j && i == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        vector<vector<int>> result;
        for(int row = 1;row <= n;row++){
            vector<int> arr;
            int i = row;
            int j = 1;
            while(i >= 1 && j <= n){
                arr.push_back(dp[i--][j++]);
            }
            result.push_back(arr);
        }
        return result;
    }
};