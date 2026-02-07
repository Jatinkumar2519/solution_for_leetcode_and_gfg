class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int mod = 1e9 + 7;

        using ll = long long;

        // ll dp[100001];
        // function<ll(int)> solve = [&](int i) -> ll {
        //     if (i == n)
        //         return 1;

        //     if (dp[i] != -1)
        //         return dp[i];

        //     if (s[i] == '0')
        //         return 0;

        //     ll count = 0;

        //     if (s[i] != '*') {
        //         count = (count + solve(i + 1)) % mod;

        //         if (i + 2 <= n) {
        //             if (s[i + 1] != '*') {

        //                 int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

        //                 if (10 <= num && num < 27) {
        //                     count = (count + solve(i + 2)) % mod;
        //                 }
        //             } else {

        //                 if(s[i] - '0' == 1){
        //                     count = (count + 9LL * solve(i + 2)) % mod;
        //                 }
        //                 if(s[i] - '0' == 2){
        //                     count = (count + 6LL * solve(i + 2)) % mod;
        //                 }
        //             }
        //         }
        //     } else {

        //         count = (count + 9 * solve(i + 1)) % mod;

        //         if (i + 2 <= n) {
        //             if(s[i + 1] != '*'){
        //                 if (s[i + 1] <= '6'){
        //                     count = (count + 2LL * solve(i + 2)) % mod;
        //                 }
        //                 else{
        //                     count = (count + solve(i + 2)) % mod;
        //                 }
        //             }
        //             else {
        //                 count = (count + 15LL * solve(i + 2)) % mod;
        //             }
        //         }
        //     }

        //     return dp[i] = count;
        // };

        // memset(dp, -1, sizeof(dp));

        // return solve(0);

        vector<ll> dp(n + 1);
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            ll count = 0;
            if (s[i] != '*') {
                count = (count + dp[i + 1]) % mod;

                if (i + 2 <= n) {
                    if (s[i + 1] != '*') {

                        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                        if (10 <= num && num < 27) {
                            count = (count + dp[i + 2]) % mod;
                        }
                    } else {

                        if (s[i] - '0' == 1) {
                            count = (count + 9LL * dp[i + 2]) % mod;
                        }
                        if (s[i] - '0' == 2) {
                            count = (count + 6LL * dp[i + 2]) % mod;
                        }
                    }
                }
            } else {

                count = (count + 9 * dp[i + 1]) % mod;

                if (i + 2 <= n) {
                    if (s[i + 1] != '*') {
                        if (s[i + 1] <= '6') {
                            count = (count + 2LL * dp[i + 2]) % mod;
                        } else {
                            count = (count + dp[i + 2]) % mod;
                        }
                    } else {
                        count = (count + 15LL * dp[i + 2]) % mod;
                    }
                }
            }

            dp[i] = count;
        }

        return dp[0];
    }
};