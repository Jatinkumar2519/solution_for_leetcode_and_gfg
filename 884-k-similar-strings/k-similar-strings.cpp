class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        map<__int128, unordered_map<int, int>> dp;

        auto getKey = [&](auto& str) -> __int128 {
            __int128 key = 0;
            for (auto& ch : str) {
                key = key * 10 + (ch - 'a');
            }

            return key;
        };

        function<int(string&, int)> solve = [&](string& str, int idx) -> int {
            if (idx == n)
                return 0;

            __int128 key = getKey(str);
            if (dp.count(key) && dp[key].count(idx))
                return dp[key][idx];

            if (s2[idx] == str[idx])
                return dp[key][idx] = solve(str, idx + 1);

            int minv = INT_MAX;

            for (int j = idx; j < n; j++) {
                if (s2[idx] == str[j]) {

                    swap(str[idx], str[j]);

                    minv = min(minv, 1 + solve(str, idx + 1));

                    swap(str[idx], str[j]);
                }
            }

            return dp[key][idx] = minv;
        };

        return solve(s1, 0);
    }
};