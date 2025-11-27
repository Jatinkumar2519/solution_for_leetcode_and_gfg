class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        using ll = long long;
        ll sum = 0;
        ll maxsum = LLONG_MIN;
        vector<ll>  sums(k,LLONG_MAX);
        sums[k - 1] = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(sums[i % k] != LLONG_MAX){
                maxsum = max(maxsum,sum - sums[i % k]);
            }
            sums[i % k] = min(sums[i % k],sum);
        }
        return maxsum;
    }
};