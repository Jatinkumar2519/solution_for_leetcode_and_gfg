class Solution {
public:
    int dp[501][501];
    bool solve(vector<int>& arr,int i,int j,int alice,int bob,bool turn){
        if(i > j) return alice > bob;
        if(dp[i][j] != -1) return dp[i][j];
        if(turn){
            return dp[i][j] = solve(arr,i + 1,j,alice + arr[i],bob,false) || solve(arr,i,j - 1,alice + arr[j],bob,false);
        }
        else{
            return dp[i][j] = solve(arr,i + 1,j,alice,bob + arr[i],true) || solve(arr,i,j - 1,alice,bob + arr[j],true);
        }
        return false;
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,n - 1,0,0,true);
    }
};