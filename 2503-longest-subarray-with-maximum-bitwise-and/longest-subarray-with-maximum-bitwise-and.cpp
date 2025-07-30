class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxv = *max_element(nums.begin(),nums.end());
        int len = 0;
        int maxlen = 0;
        for(int i = 0;i < nums.size();i++){
            if(maxv == nums[i]){
                len++;
            }
            else{
                maxlen = max(maxlen,len);
                len = 0;
            }
        }
        return max(maxlen,len);
    }
};