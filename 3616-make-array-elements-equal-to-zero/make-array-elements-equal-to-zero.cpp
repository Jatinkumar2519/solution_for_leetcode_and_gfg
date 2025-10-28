class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> sufix(n,0);
        sufix.back() = nums.back();
        for(int i = n - 2;i >= 0;i--){
            sufix[i] = sufix[i + 1] + nums[i];
        }
        int sum = 0;
        int count = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                int left = sum;
                int right = (i + 1 < n) ? sufix[i + 1] : 0;
                if(left == right){
                    count += 2;
                }
                if(abs(left - right) == 1){
                    count += 1;
                }
            }
            sum += nums[i];
        }
        return count;
    }
};