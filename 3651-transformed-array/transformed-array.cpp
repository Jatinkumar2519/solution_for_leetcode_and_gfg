class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size());
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){
                res[i] = 0;
            }
            else if(nums[i] > 0){
                res[i] = nums[(nums[i] + i) % n];
            }
            else{
                res[i] = nums[(n + (i + nums[i]) % n) % n];
            }
        }
        return res;
    }
};