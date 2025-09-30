class Solution {
public:
    int triangularSum(vector<int>& nums) {
        function<int(vector<int>)> solve = [&](vector<int> arr)->int{
            int n = arr.size();
            if(n == 1) return arr[0];
            vector<int> newarr(n - 1);
            for(int i = 0;i + 1 < n;i++){
                newarr[i] = (arr[i] + arr[i + 1]) % 10;
            }
            return solve(newarr);
        };
        return solve(nums);
    }
};