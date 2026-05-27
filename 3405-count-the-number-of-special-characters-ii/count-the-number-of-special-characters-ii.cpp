class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        
        int suffix1[26] = {0};
        int suffix2[26] = {0};

        for(int i = 0;i < word.size();i++){
            char ch = word[i];

            if('a' <= ch && ch <= 'z'){
                suffix1[ch - 'a']++;
            }

            if('A' <= ch && ch <= 'Z'){
                suffix2[ch - 'A']++;
            }
        }

        int count = 0;

        int prefix1[26] = {0};
        int prefix2[26] = {0};

        bool visit[26] = {false};

        for(int i = 0;i < n;i++){
            char ch = word[i];

            if('a' <= ch && ch <= 'z'){
                prefix1[ch - 'a']++;
                suffix1[ch - 'a']--;
            }

            if('A' <= ch && ch <= 'Z'){
                prefix2[ch - 'A']++;
                suffix2[ch - 'A']--;
            }

            for(int j = 0;j < 26;j++){
                if(visit[j]) continue;

                if(prefix1[j] > 0 && suffix1[j] == 0 && suffix2[j] > 0 && prefix2[j] == 0){
                    visit[j] = true;count++;
                }
            }
        }

        return count;
    }
};