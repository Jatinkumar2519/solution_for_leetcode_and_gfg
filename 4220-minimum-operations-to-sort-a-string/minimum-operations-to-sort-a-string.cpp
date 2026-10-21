class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        bool isSorted = true;
        for (int i = 1; i < n; i++) {
            isSorted = isSorted && (s[i - 1] <= s[i]);
        }

        if (isSorted)
            return 0;

        char mx = *max_element(s.begin(), s.end());
        char mn = *min_element(s.begin(), s.end());

        if (n == 2)
            return -1;

        if (s[0] == mn || s.back() == mx)
            return 1;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        return 3;
    }
};