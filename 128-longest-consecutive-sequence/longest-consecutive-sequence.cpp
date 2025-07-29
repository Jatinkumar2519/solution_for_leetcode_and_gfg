class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int maxlen = 0;
        for(int num : nums){
            if(set.find(num) != set.end() && set.find(num - 1) == set.end()){
                int len = 0;
                int target = num;
                while(set.find(target) != set.end()){
                    set.erase(set.find(target));
                    len++;target++;
                }
                maxlen = max(maxlen,len);
            }
        }
        return maxlen;
    }
};