class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        int left = 0;
        int right = accumulate(nums.begin(),nums.end(),0);

        for(int i = 0;i < n;i++){
            right -= nums[i];

            result[i] = abs(right - left);
            left += nums[i];
        }

        return result;
    }
};