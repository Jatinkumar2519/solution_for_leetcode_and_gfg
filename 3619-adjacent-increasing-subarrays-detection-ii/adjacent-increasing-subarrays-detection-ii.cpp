class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = 1;
        for(int i = 1;i < n;i++){
            if(nums[i - 1] < nums[i]) prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = 1;
        }
        function<bool(int)> check = [&](int k) -> bool{
            for(int i = k;i <= n - k;i++){
                int left = prefix[i - 1];
                int right = prefix[i + k - 1];
                if(left >= k && right >= k) return true;
            }
            return false;
        };
        int res = 1;
        int left = 2;
        int right = n/2;
        while(left <= right){
            int mid = (left + right)/2;
            if(check(mid)){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return res;
    }
};