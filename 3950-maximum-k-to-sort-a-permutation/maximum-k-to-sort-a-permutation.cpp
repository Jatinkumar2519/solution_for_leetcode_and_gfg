class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int num = -1;
        for(int i = 0;i < n;i++){

            if(temp[i] != nums[i]){
                if(num == -1) num = nums[i];
                else num = (num & nums[i]);
            }
        }

        return num == -1 ? 0 : num;
    }
};