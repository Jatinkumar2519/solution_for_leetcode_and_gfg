class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 0;
        int dec = 0;
        int len1 = 1;
        int len2 = 1;
        
        for(int i = 0;i < nums.size() - 1;i++){
            if(nums[i] < nums[i + 1]){
                len1++;
            }
            else{
                inc = max(inc,len1);
                len1 = 1;
            }
            if(nums[i] > nums[i + 1]){
                len2++;
            }
            else{
                dec = max(dec,len2);
                len2 = 1;
            }
        }

        inc = max(inc,len1); 
        dec = max(dec,len2);

        return max(dec,inc);
    }
};