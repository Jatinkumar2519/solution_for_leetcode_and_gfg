class Solution {
public:
    int dp[101][10001];

    int solve(int e,int f){
        if(e == 1 || f <= 1) return f;

        if(dp[e][f] != -1) return dp[e][f];

        int minv = INT_MAX;
        
        int left = 1;
        int right = f;
        while(left <= right){
            int mid = (left + right)/2;

            int broken = solve(e - 1,mid - 1);
            int not_broken = solve(e,f - mid);

            minv = min(minv,1 + max(not_broken,broken));
            if(broken > not_broken){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return dp[e][f] = minv;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};