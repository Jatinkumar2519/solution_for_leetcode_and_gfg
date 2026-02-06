class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(),nums.end());

        int num = 1;
        int maxv = *max_element(nums.begin(),nums.end());

        while(num <= maxv){
            if(set.find(num) == set.end()) return num;
            num++;
        }

        return num;
    }
};