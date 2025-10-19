class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        string res = s;
        unordered_set<string> visit;
        function<string(string)> add = [&](string str) -> string{
            for(int i = 1;i < n;i += 2){
                str[i] = '0' + ((str[i] - '0') + a) % 10;
            }
            return str;
        };
        function<string(string)> rev = [&](string str) -> string{
            reverse(str.begin(),str.end());
            reverse(str.begin(),str.begin() + b);
            reverse(str.begin() + b,str.end());
            return str;
        };
        function<void(string)> solve = [&](string curr)->void{
            if(visit.count(curr)) return;
            res = min(res,curr);
            visit.insert(curr);
            solve(add(curr));
            solve(rev(curr));         
        };
        solve(s);
        return res;
    }
};