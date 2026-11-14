class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minv = INT_MAX;

        for(int len = l;len <= r;len++){

            int sum = 0;
            for(int i = 0;i < len;i++){
                sum += nums[i];
            }

            if(sum > 0)
                minv = min(minv, sum);

            for(int i = len;i < n;i++){

                sum -= nums[i - len];
                sum += nums[i];

                if(sum > 0)
                    minv = min(minv, sum);
            }
        }

        return (minv == INT_MAX) ? -1 : minv;
    }
};