class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n = s1.length();
        unordered_map<string, int> dp;

        function<int(string&, int)> solve = [&](string& str, int idx) -> int {
            while (idx < n && str[idx] == s2[idx])
                idx++;

            if (idx == n)
                return 0;

            string key = str.substr(idx);
            if (dp.count(key))
                return dp[key];

            int minv = INT_MAX;
            for (int j = idx; j < n; j++) {
                if (s2[idx] == str[j] && s2[j] == str[idx]) {

                    swap(str[idx], str[j]);

                    minv = min(minv, 1 + solve(str, idx + 1));

                    swap(str[idx], str[j]);
                }
            }

            if (minv == INT_MAX) {
                for (int j = idx; j < n; j++) {
                    if (s2[idx] == str[j]) {

                        swap(str[idx], str[j]);

                        minv = min(minv, 1 + solve(str, idx + 1));

                        swap(str[idx], str[j]);
                    }
                }
            }
            return dp[key] = minv;
        };

        return solve(s1, 0);
    }
};