class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,-1);

        for(int i = 0;i < n;i++){
            for(int num = 0;num <= nums[i];num++){
                if((num | (num +1)) == nums[i]){
                    arr[i] = num;
                    break;
                }
            }
        }
        return arr;
    }
};