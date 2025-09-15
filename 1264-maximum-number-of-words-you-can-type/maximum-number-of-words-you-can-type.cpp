class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> map(26);
        for(char& ch : brokenLetters){
            map[ch - 'a']++;
        }
        int count = 0;
        bool flag = true;
        vector<int> arr(26);
        for(char& ch : text){
            if(ch == ' '){
                arr = vector<int>(26,0);
                if(flag) count++;
                flag = true;
            }
            else{
                arr[ch - 'a']++;
                if(map[ch - 'a'] > 0){
                    flag = false;
                }
            }
        }
        if(flag) count++;
        return count;
    }
};