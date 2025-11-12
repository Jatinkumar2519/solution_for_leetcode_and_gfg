class Solution {
public:
    int minOperations(vector<int>& nums) {
        int gcd = 0;
        int one = 0;
        int n = nums.size();
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1) one++;
            gcd = __gcd(gcd,nums[i]);
        }
        if(one > 1) return n - one;
        if(gcd > 1) return -1;
        int minl = n;
        for(int i = 0;i < n;i++){
            gcd = 0;
            for(int j = i;j < n;j++){
                gcd = __gcd(gcd,nums[j]);
                if(gcd == 1){
                    minl = min(minl,j - i + 1);
                    break;
                }
            }
        }
        return minl + n - 2;
    }
};