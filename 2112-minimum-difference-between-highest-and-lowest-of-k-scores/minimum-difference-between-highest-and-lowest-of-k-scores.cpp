class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minv = INT_MAX;

        for(int i = 0;i + k <= nums.size();i++){
            minv = min(minv,nums[i + k - 1] - nums[i]);
        }
        return minv;
    }
};