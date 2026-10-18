class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        int mod = 1e9 + 7;
        using ll = long long;

        auto power = [&](ll a, int x) -> int {
            ll res = 1;
            while (x > 0) {
                if (x & 1) {
                    res = (res * a) % mod;
                }

                a = (a * a) % mod;
                x >>= 1;
            }

            return (int)res;
        };

        vector<ll> fact(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        vector<ll> invFact(n + 1, 1);

        invFact[n] = power(fact[n], mod - 2);

        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = invFact[i + 1] * (i + 1) % mod;
        }

        auto nCr = [&](int a, int r) -> int {
            return invFact[r] * fact[a] % mod * invFact[a - r] % mod;
        };

        function<int(vector<int>&)> solve = [&](vector<int>& arr)->int{
            if(arr.empty()) return 1;
            
            int m = arr.size();
            vector<int> left,right;

            for(int i = 1;i < m;i++){
                if(arr[0] < arr[i]) right.push_back(arr[i]);
                else left.push_back(arr[i]);
            }

            int l = left.size();
            int r = right.size();

            return (ll)nCr(m - 1, l) * solve(left) % mod * solve(right) % mod;
        };

        return solve(nums) - 1;
    }
};