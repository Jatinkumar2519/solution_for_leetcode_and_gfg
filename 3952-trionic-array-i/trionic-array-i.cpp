class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1,n = nums.size();
        bool flag1 = false,flag2 = false,flag3 = false;
        while(i < n && nums[i - 1] < nums[i]){
            flag1 = true;
            i++;
        }
        while(i < n && nums[i - 1] > nums[i]){
            flag2 = true;
            i++;
        }
        while(i < n && nums[i - 1] < nums[i]){
            flag3 = true;
            i++;
        }
        return flag1 && flag2 && flag3 && i == n;
    }
};