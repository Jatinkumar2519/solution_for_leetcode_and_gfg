class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();

        vector<int> visit(26,false),freq(26,0);
        for(char ch : s) freq[ch - 'a']++;

        string str;
        for(int i = 0;i < n;i++){
            if(visit[s[i] - 'a']){
                freq[s[i] - 'a']--;
                continue;
            }

            while(!str.empty() && str.back() > s[i]){
                if(freq[str.back() - 'a'] > 0){
                    visit[str.back() - 'a'] = false;
                    str.pop_back();
                }
                else{
                    break;
                }
            }
            visit[s[i] - 'a'] = true;
            str.push_back(s[i]);
            freq[s[i] - 'a']--;
        }

        return str;
    }
};