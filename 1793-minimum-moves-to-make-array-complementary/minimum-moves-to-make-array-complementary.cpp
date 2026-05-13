class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> diff(2*limit + 2,0);

        for(int i = 0;i < n/2;i++){
            int minv = min(nums[i],nums[n - i - 1]);
            int maxv = max(nums[i],nums[n - i - 1]);
            
            diff[2] += 2;

            diff[minv + 1]--;
            diff[minv + maxv]--;

            diff[minv + maxv + 1]++;
            diff[maxv + limit + 1]++;
        }

        int minv = n;
        int curr = 0;

        for(int i = 2;i <= 2 * limit;i++){
            curr += diff[i];
            minv = min(minv,curr);
        }

        return minv;
    }
};