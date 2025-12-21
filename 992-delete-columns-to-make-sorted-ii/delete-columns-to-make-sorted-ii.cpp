class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        vector<bool> good(n, false);
        int ans = 0;

        for (int col = 0; col < m; col++) {
            bool bad = false;

            for (int i = 1; i < n; i++) {
                if (!good[i] && strs[i-1][col] > strs[i][col]) {
                    bad = true;
                    break;
                }
            }

            if (bad) {
                ans++;
                continue;
            }

            for (int i = 1; i < n; i++) {
                if (!good[i] && strs[i-1][col] < strs[i][col]) {
                    good[i] = true;
                }
            }
        }

        return ans;
    }
};
