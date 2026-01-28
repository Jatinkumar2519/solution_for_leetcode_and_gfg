class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1;
        int vote = 0;
        for(int i = 0;i < nums.size();i++){
            if(vote == 0){
                major = nums[i];
            }

            if(major != nums[i]) vote++;
            else vote--;
        }
        
        return major;
    }
};