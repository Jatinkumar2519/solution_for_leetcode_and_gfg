class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;

        long long num = 0;
        for(int i = 1;i <= n;i++){
            int len = log2(i) + 1;
            
            // for(int j = 0;j < len;j++){
                num = (num << len) % mod;
            // }

            num = (num + i) % mod;
        } 

        return num;
    }
};