class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        for(char ch : text) freq[ch - 'a']++;

        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;

        int minv = INT_MAX;
        string bal = "balloon";
        
        for(char ch : bal) minv = min(minv,freq[ch - 'a']);

        return minv;
    }
};