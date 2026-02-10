class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int maxlen = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            unordered_set<int> set1,set2;
            for(int j = i;j < n;j++){
                if(nums[j] % 2 == 0){
                    set1.insert(nums[j]);
                }
                else{
                    set2.insert(nums[j]);
                }
                if(set1.size() == set2.size()){
                    maxlen = max(maxlen,j - i + 1);
                }
            }
        }
        return maxlen;
    }
};