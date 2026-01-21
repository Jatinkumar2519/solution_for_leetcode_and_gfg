class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n);

        for(int i = 0;i < nums.size();i++){
            if(nums[i] % 2 == 0){
                arr[i] = -1;
            }
            else{
                for(int b = 31;b >= 0;b--){
                    if(nums[i] & (1 << b)){

                        int num = (nums[i] & (~(1 << b)));

                        if((num | (num + 1)) == nums[i]){
                            arr[i] = num;
                            break;
                        }
                    }
                }
            }
        }
        return arr;
    }
};