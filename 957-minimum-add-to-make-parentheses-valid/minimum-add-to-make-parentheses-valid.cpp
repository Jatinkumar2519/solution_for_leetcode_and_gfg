class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(auto ch : s){
            if(!stk.empty() && stk.top() == '(' && ch == ')') stk.pop();
            else stk.push(ch);
        }

        return stk.size();
    }
};