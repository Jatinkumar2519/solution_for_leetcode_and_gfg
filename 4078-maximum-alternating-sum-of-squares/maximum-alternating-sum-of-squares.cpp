class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end(),[&](int num1,int num2){
            return abs(num1) > abs(num2);
        });

        long long sum = 0;
        for(int i = 0;i < n;i++){

            if(i < (n + 1)/2) sum += (nums[i] * nums[i]);
            else sum -= (nums[i] * nums[i]);
        }

        return sum;
    }
};