class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        stack<int> stk;
        vector<bool> visit(n,false);

        for(int i = 0;i < n;i++){
            if(!stk.empty() && s[stk.top()] == '(' && s[i] == ')'){

                int front = stk.top();stk.pop();
                if(stk.empty()){
                    visit[front] = visit[i] = true;
                }
            }
            else{
                stk.push(i);
            }
        }

        string res;
        for(int i = 0;i < n;i++){
            if(!visit[i]) res.push_back(s[i]);
        }

        return res;
    }
};