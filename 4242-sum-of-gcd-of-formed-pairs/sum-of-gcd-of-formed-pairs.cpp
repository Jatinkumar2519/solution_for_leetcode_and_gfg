class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        using ll = long long;
        int n = nums.size();

        vector<int> arr(n);
        int maxv = nums[0];

        for(int i = 0;i < n;i++){
            maxv = max(maxv,nums[i]);
            arr[i] = __gcd(maxv,nums[i]);
        }

        sort(arr.begin(),arr.end());

        int i = 0;
        int j = n - 1;

        ll sum = 0;
        while(i < j){
            sum += __gcd(arr[i++],arr[j--]);
        }

        return sum;
    }
};