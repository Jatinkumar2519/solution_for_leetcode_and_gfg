class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();

        function<int(int,int)> solve = [&](int i,int j)->int{
            if(i >= j) return 0;
            
            int res = 0;
            stack<char> stk;

            for(int k = i;k <= j;k++){

                if(!stk.empty() && stk.top() == '(' && s[k] == ')'){
                    stk.pop();
                }
                else{
                    stk.push(s[k]);
                }

                if(stk.empty()){
                    if(k - i == 1){
                        res += 1;
                    }
                    else{
                        res += 2 * solve(i + 1,k - 1);
                    }

                    i = k + 1;
                }
            }

            return res;
        };

        return solve(0,n - 1);
    }
};