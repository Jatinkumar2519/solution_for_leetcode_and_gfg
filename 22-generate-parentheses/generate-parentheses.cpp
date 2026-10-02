class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        string curr;
        vector<string> result;

        function<void(int,int,int)> solve = [&](int idx,int open,int close)->void{
            if(close > open || open > n) return;
            if(idx == n * 2){
                if(open == close){
                    result.push_back(curr);
                }
                return;
            }

            curr.push_back('(');
            solve(idx + 1,open + 1,close);
            curr.pop_back();

            curr.push_back(')');
            solve(idx + 1,open,close + 1);
            curr.pop_back();
        };

        solve(0,0,0);
        return result;
    }
};