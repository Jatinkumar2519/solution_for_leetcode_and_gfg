class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        int dp[101][201][2];
        function<int(int,int,int)> solve = [&](int idx,int m,int myTurn)->int{
            if(idx == n) return 0;
            if(dp[idx][m][myTurn] != -1) return dp[idx][m][myTurn];

            int gain = (myTurn) ? 0 : INT_MAX;
            int sum = 0;

            for(int j = idx,x = 1;j < n && x <= 2 * m;j++,x++){
                sum += piles[j];

                if(myTurn){
                    gain = max(gain,sum + solve(j + 1,max(m,x),0));
                }
                else{
                    gain = min(gain,solve(j + 1,max(m,x),1));
                }
            }

            return dp[idx][m][myTurn] = gain;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,1,1);
    }
};