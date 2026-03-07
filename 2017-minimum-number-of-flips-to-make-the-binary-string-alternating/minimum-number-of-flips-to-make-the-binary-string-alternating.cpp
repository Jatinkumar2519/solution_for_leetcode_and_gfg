class Solution {
public:
    int minFlips(string s) {

        int n = s.length();
        s += s;

        int count1 = 0,count2 = 0;
        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                count1 += (s[i] == '0');
                count2 += (s[i] == '1');
            }
            else{
                count1 += (s[i] == '1');
                count2 += (s[i] == '0');
            }
        }

        int minv = min(count1,count2);

        for(int i = n;i < 2 * n;i++){
            int prev = i - n;
            int curr = i;

            if(prev % 2 == 0){
                count1 -= (s[prev] == '0');
                count2 -= (s[prev] == '1');
            }
            else{
                count1 -= (s[prev] == '1');
                count2 -= (s[prev] == '0');
            }

            if(curr % 2 == 0){
                count1 += (s[curr] == '0');
                count2 += (s[curr] == '1');
            }
            else{
                count1 += (s[curr] == '1');
                count2 += (s[curr] == '0');
            }

            minv = min({minv,count1,count2});
        }

        return minv;
    }
};