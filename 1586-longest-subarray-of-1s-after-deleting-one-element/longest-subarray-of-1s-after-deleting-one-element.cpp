class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int sum = 0;
        bool flag = false;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                sum = 0;
                flag = true;
            }
            else{
                sum += nums[i];
            }
            arr[i] = sum;
        }
        int cont_one = 0;
        int maxone = 0;
        for(int i = n - 1;i >= 0;i--){
            if(arr[i] == 0){
                maxone = 0;
            }
            else{
                maxone = max(maxone,arr[i]);
            }
            arr[i] = maxone;
            cont_one = max(cont_one,arr[i]);
        }
        int res = 0;
        for(int i = 1;i < n - 1;i++){
            if(nums[i] == 0){
                res = max(res,arr[i - 1] + arr[i + 1]);
            }
        }
        if(!flag)
            cont_one--;
        return max(res,cont_one);
    }
};