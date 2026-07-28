class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        int freq[26] = {0};

        for(char ch : s) freq[ch - 'a']++;
        string res(n,' ');

        int i = 0;
        int j = n - 1;
        for(int c = 0;c < 26;c++){

            char ch = ('a' + c);

            while(freq[c] >= 2){
                res[i] = res[j] = ch;
                i++;j--;freq[c] -= 2;
            }
        }

        for(int c = 0;c < 26;c++){
            if(freq[c]){
                res[i] = ('a' + c);
                break;
            }
        }
        
        return res;
    }
};