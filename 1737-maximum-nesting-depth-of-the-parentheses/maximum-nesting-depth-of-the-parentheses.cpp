class Solution {
public:
    int maxDepth(string str) {
        int maxv = 0;
        stack<char> s;

        for (char ch : str) {
            if (ch == '(') {
                s.push(ch);
            } else if(ch == ')') {
                s.pop();
            }

            maxv = max(maxv, (int)s.size());
        }

        return maxv;
    }
};