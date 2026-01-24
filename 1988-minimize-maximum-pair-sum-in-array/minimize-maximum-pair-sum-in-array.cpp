class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        int i = 0;
        int j = n - 1;

        int maxv = 0;
        while(i < j){
            maxv = max(maxv,nums[i++] + nums[j--]);
        }
        return maxv;
    }
};