class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;

        // static int dp[201][201][201][2];

        // function<int(int,int,int,int)> solve = [&](int a,int b,int c,int d)->int{
        //     if(a == 0 && b == 0){
        //         return c <= limit;
        //     }
        //     if(c > limit || a < 0 || b < 0) return 0;

        //     if(dp[a][b][c][d] != -1) return dp[a][b][c][d];

        //     return dp[a][b][c][d] = (solve(a - 1,b,(d ? 1 : c + 1),0) + solve(a,b - 1,(d ? c + 1 : 1),1)) % mod;
        // };

        // memset(dp,-1,sizeof(dp));

        // return (solve(zero - 1,one,1,0) + solve(zero,one - 1,1,1)) % mod;

        static int dp[201][201][201][2];
        memset(dp,0,sizeof(dp));

        if(zero > 0) dp[1][0][1][0] = 1;
        if(one > 0) dp[0][1][1][1] = 1;

        for(int i = 0; i <= zero; i++){
            for(int j = 0; j <= one; j++){
                for(int c = 1; c <= limit; c++){
                    for(int d = 0; d < 2; d++){

                        int val = dp[i][j][c][d];
                        if(val == 0) continue;

                        // place 0
                        if(i + 1 <= zero){
                            int nc = (d == 0 ? c + 1 : 1);
                            if(nc <= limit){
                                dp[i+1][j][nc][0] =
                                (dp[i+1][j][nc][0] + val) % mod;
                            }
                        }

                        // place 1
                        if(j + 1 <= one){
                            int nc = (d == 1 ? c + 1 : 1);
                            if(nc <= limit){
                                dp[i][j+1][nc][1] =
                                (dp[i][j+1][nc][1] + val) % mod;
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;

        for(int c = 1; c <= limit; c++){
            ans = (ans + dp[zero][one][c][0]) % mod;
            ans = (ans + dp[zero][one][c][1]) % mod;
        }

        return ans;
    }
};