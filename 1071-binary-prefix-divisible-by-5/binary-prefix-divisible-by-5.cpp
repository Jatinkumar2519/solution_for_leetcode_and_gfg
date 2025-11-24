class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        int n = nums.size();
        vector<bool> result(n);
        for(int i = 0;i < n;i++){
            num = num | nums[i];
            num = num % 5;
            result[i] = (num == 0);
            num = num << 1;
        }
        return result;
    }
};