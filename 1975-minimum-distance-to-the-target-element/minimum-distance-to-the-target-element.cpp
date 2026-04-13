class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int j = start;

        while(true){
            if(i >= 0 && nums[i] == target) return start - i;
            if(j < nums.size() && nums[j] == target) return j - start;
            i--;j++;
        }

        return 0;
    }
};