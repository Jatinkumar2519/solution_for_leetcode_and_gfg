class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        if(accumulate(nums.begin(),nums.end(),0) < x) return -1;
        
        for(int i = 0;i < n;i++) nums.push_back(nums[i]);

        int left = 0;
        int minl = INT_MAX;

        int sum = 0;
        for(int i = 0;i < 2 * n;i++){

            sum += nums[i];
            while(sum > x){

                sum -= nums[left];
                left++;
            }

            if(sum == x && (left == 0 || (left + 1 <= n && i + 1 >= n))){
                minl = min(minl,i - left + 1);
            }
        }

        return (minl == INT_MAX) ? -1 : minl;
    }
};