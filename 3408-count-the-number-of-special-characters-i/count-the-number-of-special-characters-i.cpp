class Solution {
public:
    int numberOfSpecialChars(string word) {
        int freq1[26] = {0};
        int freq2[26] = {0};

        for(auto& ch : word){
            if('a' <= ch && ch <= 'z'){
                freq1[ch - 'a']++;
            }

            if('A' <= ch && ch <= 'Z'){
                freq2[ch - 'A']++;
            }
        }

        int count = 0;
        for(int i = 0;i < 26;i++){
            count += (freq1[i] > 0 && freq2[i] > 0);
        }

        return count;
    }   
};