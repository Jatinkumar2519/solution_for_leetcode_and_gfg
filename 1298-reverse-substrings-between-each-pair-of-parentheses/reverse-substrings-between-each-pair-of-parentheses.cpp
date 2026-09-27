class Solution {
public:
    string reverseParentheses(string sex) {

        sex = '(' + sex;
        sex =  sex + ')';

        stack<char> b;
        stack<string> s;

        for(char ch : sex){
            if(ch == '('){
                b.push(ch);
                s.push(string(1,ch));
            }
            else if(ch == ')'){
                string str;

                while(!s.empty() && s.top() != "("){
                    str += s.top();s.pop();
                }
                
                s.pop();
                b.pop();
                
                reverse(str.begin(),str.end());
                s.push(str);
            }
            else{
                s.push(string(1,ch));
            }
        }
        
        return s.top();
    }
};