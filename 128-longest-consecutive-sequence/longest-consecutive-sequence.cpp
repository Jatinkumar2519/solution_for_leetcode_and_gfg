class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxl = 0;
        unordered_set<int> set(nums.begin(),nums.end());
        for(int num : nums){
            if(set.find(num) != set.end() && set.find(num - 1) == set.end()){
                int len = 0;
                while(set.find(num) != set.end()){
                    set.erase(num);len++;num++;
                }
                maxl = max(maxl,len);
            }
        }
        return maxl;
    }
};