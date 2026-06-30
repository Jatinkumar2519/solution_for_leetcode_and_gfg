class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();

        int left = 0;
        int count = 0;

        int freq[3] = {0};

        for(int i = 0;i < n;i++){
            freq[s[i] - 'a']++;

            while(min({freq[0],freq[1],freq[2]}) > 0){
                count += n - i;
                freq[s[left] - 'a']--;
                left++;
            }
        }

        return count;
    }
};