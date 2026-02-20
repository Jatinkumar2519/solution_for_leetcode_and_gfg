class Solution {
public:
    string convert(string s, int n) {
        if(n == 1) return s;
        vector<string> result(n,"");
        int j = 0;bool forw = true;
        for(int i = 0;i < s.length();i++){
            result[j].push_back(s[i]);
            if(j == n - 1){
                forw = false;
            }
            if(j == 0){
                forw = true;
            }
            if(forw){
                j++;
            }
            if(!forw){
                j--;
            }
        }
        string str = "";
        for(string & x : result){
            str += x;
        }
        return str;
    }
};