class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int mid = nums[n/2];

        int count = 0;
        for(int num : nums) count += abs(num - mid);

        return count;
    }
};