class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = k;i <= n - k;i++){
            bool flag = true;
            for(int j = i - k;j + 1< i;j++){
                if(nums[j] >= nums[j + 1]){
                    flag = false;
                    break;
                }
            }
            
            for(int j = i;j + 1 < i + k;j++){
                if(nums[j] >= nums[j + 1]){
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};