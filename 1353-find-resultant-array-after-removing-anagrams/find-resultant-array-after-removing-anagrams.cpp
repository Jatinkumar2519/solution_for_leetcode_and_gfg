class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        vector<bool> visit(n,false);
        for(int i = 0;i < n;i++){
            if(visit[i]) continue;
            visit[i] = true;
            result.push_back(words[i]);
            int chars_i[26];memset(chars_i,0,sizeof(chars_i));
            for(auto& ch : words[i]) chars_i[ch - 'a']++;
            for(int j = i + 1;j < n;j++){
                if(visit[j]) continue;
                int chars_j[26];memset(chars_j,0,sizeof(chars_j));
                for(auto& ch : words[j]) chars_j[ch - 'a']++;
                bool flag = true;
                for(int k = 0;k < 26;k++){
                    if(chars_i[k] != chars_j[k]){
                        flag = false;break;
                    }
                }
                if(flag){
                    visit[j] = true;
                }
                else{
                    break;
                }
            }
        }
        return result;
    }
};