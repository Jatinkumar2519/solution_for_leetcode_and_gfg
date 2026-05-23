class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return true; 

        for(int i = 0;i < n;i++){
            nums.push_back(nums[i]);
        }
        
        int count = 1;
        for(int i = 1;i < nums.size();i++){
            if(nums[i - 1] <= nums[i]) count++;
            else count = 1;

            if(count == n) return true;
        }

        return false;
    }
};