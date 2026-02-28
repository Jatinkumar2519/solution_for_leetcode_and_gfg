class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;

        long long num = 0;
        int len = 0;
        for(int i = 1;i <= n;i++){
            if((i & (i - 1)) == 0) len++;

            num = (num << len) % mod;
            num = (num + i) % mod;
        } 

        return num;
    }
};