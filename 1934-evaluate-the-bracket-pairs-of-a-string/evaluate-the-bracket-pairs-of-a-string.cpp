class Solution {
public:
    string evaluate(string sex, vector<vector<string>>& knowledge) {
        unordered_map<string,string> map;
        for(vector<string> know : knowledge){
            map[know[0]] = know[1];
        }

        string res;
        stack<char> b, s;

        for(char ch : sex){
            if(ch == '('){
                b.push(ch);
                s.push(ch);
            }
            else if(ch == ')'){
                string str;

                while(!s.empty() && s.top() != '('){
                    str.push_back(s.top());s.pop();
                }
                
                s.pop();
                b.pop();

                reverse(str.begin(),str.end());
                
                if(map.count(str)){
                    res += map[str];
                }
                else{
                    res += '?';
                }
            }
            else{
                if(b.empty()){
                    res.push_back(ch);
                }
                else{
                    s.push(ch);
                }
            }
        }

        return res;
    }
};