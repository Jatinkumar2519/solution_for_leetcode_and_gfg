class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32] = {0};
        for(int num : nums){
            for(int b = 0;b < 32;b++){
                if(num & (1 << b))
                    bit[b]++;
            }
        }

        int res = 0;
        
        for(int b = 0;b < 32;b++){
            if(bit[b] % 3 != 0){
                res |= (1 << b);
            }
        }
        return res;
    }
};