class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.length();
        int maxv = 0;
        stack<pair<char,int>> s;

        for(int i = 0;i < n;i++){
            if(!s.empty() && s.top().first == '(' && str[i] == ')'){
                s.pop();
                if(s.empty()){
                    maxv = max(maxv,i + 1);
                }
                else{
                    maxv = max(maxv,i - s.top().second);
                }
            }
            else{
                s.push({str[i],i});
            }
        }

        return maxv;
    }
};