class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[n - 1] = nums[n - 1];
        for(int i = n - 2;i >= 0;i--){
            prefix[i] = prefix[i + 1] + nums[i];
        }
        int sum = 0,count = 0;
        for(int i = 0;i + 1 < n;i++){
            sum += nums[i];
            if(abs(sum - prefix[i + 1]) % 2 == 0) count++;
        }
        return count;
    }
};