class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int num = k;
        unordered_set<int> set(nums.begin(), nums.end());
        while (set.count(num)) {
            num += k;
        }
        return num;
    }
};