class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int maxv = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n - 2;i++){
            if(nums[i] + nums[i + 1] > nums[i + 2]){
                maxv = max(maxv,nums[i] + nums[i + 1] + nums[i + 2]);
            }
        }
        return maxv;
    }
};