class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;

        int sum = 0;
        vector<int> temp = {1,0};
        
        for(int i = 0;i < n;i++){
            sum += arr[i];
            temp[sum % 2]++;
        }

        return (temp[0] * 1LL * temp[1]) % mod;
    }
};