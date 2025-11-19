class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> set(nums.begin(),nums.end());
        while(set.count(original)){
            original *= 2;
        }
        return original ;
    }
};