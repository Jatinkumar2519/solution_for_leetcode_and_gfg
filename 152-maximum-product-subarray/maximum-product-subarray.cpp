class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minv = nums[0];
        int maxv = nums[0];
        int res = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(nums[i] < 0){
                swap(minv,maxv);
            }
            minv = min(minv * nums[i],nums[i]);
            maxv = max(maxv * nums[i],nums[i]);
            res = max(res,maxv);
        }
        return res;
    }
};