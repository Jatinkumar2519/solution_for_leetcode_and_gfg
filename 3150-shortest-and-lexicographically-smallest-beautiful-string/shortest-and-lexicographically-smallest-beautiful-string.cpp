class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string minv;
        int minl = INT_MAX;

        int sum = 0;
        int left = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            sum += (s[i] == '1');

            while (sum >= k) {
                if (sum == k) {
                    int len = i - left + 1;
                    if (minl > len) {
                        minl = len;
                        minv = s.substr(left, len);
                    } else if (minl == len) {
                        minv = min(minv, s.substr(left, len));
                    }
                }
                sum -= (s[left] == '1');
                left++;
            }
        }
        return (minv.empty()) ? "" : minv;
    }
};