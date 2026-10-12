class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod = 1e9 + 7;
        vector<int> bits(32,0);

        for(int num : nums){
            
            for(int b = 0;b < 32;b++){
                bits[b] += ((num & (1 << b)) > 0);
            }
        }

        int sum = 0;
        for(int i = 0;i < k;i++){

            int curr = 0;
            for(int b = 0;b < 32;b++){

                if(bits[b]){
                    bits[b]--;
                    curr |= (1 << b);
                }
            }

            sum = (sum + (curr * 1LL * curr) % mod) % mod;
        }

        return sum;
    }
};