class Solution {
public:
    unordered_set<int> set;
    void solve(string& s,int mask,string num){
        if(num.length() == s.length()){
            if(num.back() == '0') return;
            reverse(num.begin(),num.end());
            set.insert(stoi(num));
            return;
        }
        if(num.length() > 0 && (num[0] - '0') % 2 != 0) return;
        for(int i = 0;i < s.length();i++){
            if(mask & (1 << i)) continue;
            solve(s,mask | (1 << i),num + s[i]);
        }
    }
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        solve(num,0,"");
        for(auto& x : set){
            if(__builtin_popcount(x) == 1) return true;
        }
        return false;
    }
};