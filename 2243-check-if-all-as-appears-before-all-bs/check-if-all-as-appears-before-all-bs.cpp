class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int idx = 0;

        while(idx < n && s[idx] == 'a') idx++;
        while(idx < n && s[idx] == 'b') idx++;

        return idx == n;
    }
};