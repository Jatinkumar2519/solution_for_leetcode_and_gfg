class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minv = INT_MAX;
        int n = nums.size();

        for(int i = 1;i < n;i++){
            for(int j = i + 1;j < n;j++){
                minv = min(minv,nums[0] + nums[j] + nums[i]);
            }
        }
        return minv;
    }
};