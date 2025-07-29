class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> bit(32,-1);
        vector<int> res(n);
        for(int i = n - 1;i >= 0;i--){
            for(int j = 0;j < 32;j++){
                if(nums[i] & (1 << j)){
                    bit[j] = i;
                }
            }
            int indx = i;
            for(int j = 0;j < 32;j++){
                if(bit[j] != -1){
                    indx = max(indx,bit[j]);
                }
            }
            res[i] = indx - i + 1;
        }
        return res;
    }
};