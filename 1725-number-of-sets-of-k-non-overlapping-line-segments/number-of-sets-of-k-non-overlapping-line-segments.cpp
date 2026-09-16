class Solution {
public:
    int numberOfSets(int n, int k) {
        int mod = 1e9 + 7;
        int dp[1002][1002][2];

        function<int(int,int,int)> solve = [&](int x,int y,int open)->int{
            if(y == k) return (open) ? n - x : 1;
            if(x == n) return 0;

            if(dp[x][y][open] != -1) return dp[x][y][open];

            long long count = 0;

            if(open){
                count = (count + solve(x + 1,y,true)) % mod;
                count = (count + solve(x ,y + 1,false)) % mod;
            }
            else{
                count = (count + solve(x + 1,y,true)) % mod;
                count = (count + solve(x + 1,y,false)) % mod;
            }

            return dp[x][y][open] = count;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};