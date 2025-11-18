class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // int dp[1001];
        int n = bits.size();
        // memset(dp,-1,sizeof(dp));
        // function<int(int)> solve = [&](int i)->int{
        //     if(i >= n) return false;
        //     if(i == n - 1) return bits[i] == 0;
        //     if(dp[i] != -1) return dp[i];
        //     int res = 0;
        //     if(bits[i] == 1){
        //         res |= solve(i + 2);
        //     }
        //     else{

        //     }
        // }
        int i = 0;
        while(i < n){
            if(bits[i] == 1){
                i += 2;
            }
            else{
                if(i == n - 1) return true;
                i++;
            }
        }
        return false;
    }
};