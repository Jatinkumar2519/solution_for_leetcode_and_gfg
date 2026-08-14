class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {0};
        int n = s.length();
        
        int left = 0;
        int maxl = 0;

        for(int i = 0;i < n;i++){
            freq[s[i] - 'a']++;
            while(freq[s[i] - 'a'] > 2){
                freq[s[left] - 'a']--;
                left ++;
            }

            maxl = max(maxl,i - left + 1);
        }

        return maxl;
    }
};