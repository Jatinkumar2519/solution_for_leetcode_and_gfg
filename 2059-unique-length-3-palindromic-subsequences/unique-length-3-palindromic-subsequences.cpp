class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<int>> prefix(26,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            prefix[s[i] - 'a'][i]++;
        }
        for(int i = 0;i < 26;i++){
            int sum = 0;
            for(int j = 0;j < n;j++){
                sum += prefix[i][j];
                prefix[i][j] = sum;
            }
        }
        auto getsum = [&](char ch,int l,int r){
            if(l == 0)
                return prefix[ch - 'a'][r];
            return prefix[ch - 'a'][r] - prefix[ch - 'a'][l - 1];
        };
        int count = 0;
        unordered_set<string> visit;
        for(int i = 1;i + 1 < n;i++){
            for(int j = 0;j < 26;j++){
                char ch = 'a' + j;
                bool flg = (min(getsum(ch,0,i - 1),getsum(ch,i + 1,n - 1)) > 0);
                string str = string(1,ch) + s[i] + ch;
                if(visit.count(str) == 0 && flg){
                    count++;
                    visit.insert(str);
                }
            }
        }
        return count;
    }
};