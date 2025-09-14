class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist,vector<string>& queries) {
        unordered_set<string> set;
        unordered_map<string,string> map1,map2;
        function<string(string)> lower = [&](string s) -> string{
            for (char &c : s) {
                c = tolower(c);
            }
            return s;
        };
        function<bool(char)> isVowel = [&](char ch) -> bool {
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u');
        };
        function<string(string)> simplify = [&](string s) -> string{
            for(auto& ch : s){
                if(isVowel(ch)){
                    ch = '*';
                }
            }
            return s;
        };
        function<string(string)> solve = [&](string s) -> string{
            if(set.count(s)) return s;
            string str = lower(s);
            if(map1.count(str)) return map1[str];
            str = simplify(str);
            if(map2.count(str)) return map2[str];
            return "";
        };
        for(auto& s : wordlist){
            set.insert(s);
            string str = lower(s);
            if(map1.count(str) == 0){
                map1[str] = s;
            }
            str = simplify(str);
            if(map2.count(str) == 0){
                map2[str] = s;
            }
        }
        vector<string> result;
        for(auto& s : queries){
            result.push_back(solve(s));
        }
        return result;
    }
};