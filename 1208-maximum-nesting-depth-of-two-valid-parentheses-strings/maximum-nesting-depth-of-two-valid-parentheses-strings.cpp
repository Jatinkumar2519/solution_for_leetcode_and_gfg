class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();

        int maxD = 0;
        stack<char> s;

        for (auto& ch : seq) {
            if (!s.empty() && s.top() == '(' && ch == ')')
                s.pop();
            else
                s.push(ch);

            maxD = max(maxD, (int)s.size());
        }

        stack<int> stk;
        vector<int> result(n, 0);

        for (int i = 0; i < n; i++) {

            if (!stk.empty() && seq[stk.top()] == '(' && seq[i] == ')') {

                if (stk.size() > maxD / 2) {
                    result[stk.top()] = 1;
                    result[i] = 1;
                }

                stk.pop();
            }
            else {
                stk.push(i);
            }
        }

        return result;
    }
};