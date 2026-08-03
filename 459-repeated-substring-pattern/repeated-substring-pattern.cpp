class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        vector<int> lps(n, 0);

        int j = 0;
        int i = 1;

        while (i < n) {
            while (j > 0 && s[j] != s[i])
                j = lps[j - 1];
            if (s[j] == s[i])
                j++;

            lps[i++] = j;
        }

        int len = min(lps[n - 1], n - lps[n - 1]);

        if (len == 0 || n % len != 0)
            return false;
        string pat = s.substr(0, len);

        i = len;
        while (i + len <= n) {
            string str = s.substr(i, len);
            if (str != pat)
                return false;
            i += len;
        }

        return true;
    }
};