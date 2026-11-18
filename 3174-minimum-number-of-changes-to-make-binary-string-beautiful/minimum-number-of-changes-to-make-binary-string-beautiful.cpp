class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int count = 0;

        for(int i = 0;i + 2 <= n;i += 2) count += s[i + 1] != s[i];

        return count;
    }
};