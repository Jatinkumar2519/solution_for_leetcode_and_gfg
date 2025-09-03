class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxv = INT_MIN,minv = INT_MAX;
        int sum1 = 0,sum2 = 0;
        int total = 0;
        for(int i = 0;i < nums.size();i++){
            sum1 = max(sum1 + nums[i],nums[i]);
            maxv = max(maxv,sum1);
            sum2 = min(sum2 + nums[i],nums[i]);
            minv = min(minv,sum2);
            total += nums[i];
        }
        if(total == minv) return maxv;
        return max(maxv,total - minv);
    }
};