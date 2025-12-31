class Solution {
public:
    int minimumPossibleSum(int n, long long target) {
        int half = target / 2;

        int mod = 1e9 + 7;

        long long left = min(half,n);

        long long sum = ((left * 1LL * (left + 1)) / 2) % mod;

        n -= left;

        sum = (sum + (((target + n - 1) * 1LL * (target + n)) / 2) % mod) % mod;
        sum = (sum - (((target - 1) * 1LL * target) / 2) % mod + mod) % mod;

        return sum;
    }
};