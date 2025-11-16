class Solution {
public:
    int numSub(string s) {
        int count = 0;
        int one = 0;
        int mod = 1e9 + 7;
        for(auto& ch : s){
            if(ch == '1'){
                one++;
            }
            else{
                one = 0;
            }
            count = (count + one) % mod;
        }
        return count;
    }
};