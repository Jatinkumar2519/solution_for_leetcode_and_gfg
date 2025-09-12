class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(char& ch : s){
            count += (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
        }
        return count > 0;
    }
};