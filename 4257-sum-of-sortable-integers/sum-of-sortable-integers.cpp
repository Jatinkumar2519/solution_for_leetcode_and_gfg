class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        int len = log2(n) + 1;
        vector<vector<int>> tableMin(n, vector<int>(len));
        vector<vector<int>> tableMax(n, vector<int>(len));

        for (int i = 0; i < n; i++) {
            tableMin[i][0] = tableMax[i][0] = nums[i];
        }

        for (int j = 1; j < len; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {

                tableMin[i][j] = min(tableMin[i][j - 1],
                                     tableMin[i + (1 << (j - 1))][j - 1]);
                tableMax[i][j] = max(tableMax[i][j - 1],
                                     tableMax[i + (1 << (j - 1))][j - 1]);
            }
        }

        vector<int> breaks(n);
        for (int i = 1; i < n; i++) {

            breaks[i] = breaks[i - 1];
            if (nums[i - 1] > nums[i]) {
                breaks[i]++;
            }
        }

        auto getMin = [&](int l, int r) -> int {
            int k = log2(r - l + 1);

            return min(tableMin[l][k], tableMin[r - (1 << k) + 1][k]);
        };

        auto getMax = [&](int l, int r) -> int {
            int k = log2(r - l + 1);

            return max(tableMax[l][k], tableMax[r - (1 << k) + 1][k]);
        };

        auto check = [&](int k) -> bool {
            for (int i = 0; i + k <= n; i += k) {

                int j = i + k - 1;
                int b = (i > 0) ? breaks[j] - breaks[i - 1] : breaks[j];

                if (b > 1 || (b == 1 && nums[i] < nums[j]))
                    return false;
                
                int left = (i == 0) ? INT_MIN : getMax(0, i - 1);
                int right = (j == n - 1) ? INT_MAX : getMin(j + 1, n - 1);

                if(left > getMin(i, j) || getMax(i, j) > right) return false;
            }

            return true;
        };

        int res = 0;
        for (int i = 1; i * i <= n; i++) {

            if (n % i == 0) {

                if (check(i))
                    res += i;
                if (i != (n / i) && check(n / i))
                    res += (n / i);
            }
        }

        return res;
    }
};