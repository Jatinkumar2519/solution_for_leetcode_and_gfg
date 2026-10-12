class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int total = 0;
        int m = digits.size();

        vector<char> digit;
        for(auto& dig : digits) digit.push_back(dig[0]);

        int len = to_string(n).length();

        for (int i = 1; i < len; i++) {
            total += pow(m, i);
        }

        int dp[10][2];
        string num = to_string(n);

        function<int(int, int)> solve = [&](int idx, int tight) -> int {
            if (idx == len)
                return 1;
            if (dp[idx][tight] != -1)
                return dp[idx][tight];

            int count = 0;
            for (char d : digit) {
                if ((d > num[idx]) && tight)
                    continue;

                count += solve(idx + 1, tight && (num[idx] == d));
            }

            return dp[idx][tight] = count;
        };

        memset(dp, -1, sizeof(dp));
        total += solve(0, 1);

        return total;
    }
};