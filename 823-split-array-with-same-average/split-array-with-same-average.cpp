class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        unordered_map<string,bool> dp;
        function<bool(int,int,int)> solve = [&](int i,int k,int target){
            if(k == 0) return target == 0;
            if(target < 0 || k < 0 || i >= n) return false;
            string key = to_string(i) + '/' + to_string(k) + '/' + to_string(target);
            if(dp.count(key)) return dp[key];
            return dp[key] = (solve(i + 1,k - 1,target - nums[i]) || solve(i + 1,k,target));
        };
        for(int k = 1;k <= n/2;k++){
            if((sum * k) % n != 0) continue;
            dp.clear();
            int target = (sum * k) / n;
            if(solve(0,k,target)) return true;
        }
        return false;
    }
};