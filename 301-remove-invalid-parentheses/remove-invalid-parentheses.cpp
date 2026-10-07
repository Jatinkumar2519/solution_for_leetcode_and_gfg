class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        unordered_set<string> unique;

        string curr;
        int maxl = 0;

        function<void(int, int, int)> solve = [&](int idx, int open,
                                                  int close) -> void {
            if (close > open)
                return;
            if (idx == n) {
                if (open == close) {
                    int len = open + close;

                    if (maxl < len) {
                        unique = unordered_set<string>();
                        unique.insert(curr);
                        maxl = len;
                    } else if (maxl == len) {
                        unique.insert(curr);
                    }
                }

                return;
            }

            if (s[idx] != '(' && s[idx] != ')') {
                curr.push_back(s[idx]);
                solve(idx + 1,open,close);
                curr.pop_back();
            }
            else {
                solve(idx + 1, open, close);

                curr.push_back(s[idx]);
                solve(idx + 1, open + (s[idx] == '('), close + (s[idx] == ')'));
                curr.pop_back();
            }
        };

        solve(0, 0, 0);
        return vector<string>(unique.begin(), unique.end());
    }
};