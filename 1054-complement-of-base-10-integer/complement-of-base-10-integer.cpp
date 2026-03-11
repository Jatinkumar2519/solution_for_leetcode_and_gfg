class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int len = log2(n) + 1;

        int res = 0;
        for(int i = 0;i < len;i++){
            if((n & (1 << i)) == 0){
                res = res | (1 << i);
            }
        }

        return res;
    }
};