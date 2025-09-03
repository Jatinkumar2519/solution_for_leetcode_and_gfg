class Solution {
public:
    int reverseBits(int n) {
        int res = 0;
        bool flag = false;
        for(int i = 31;i >= 0;i--){
            if(n & (1 << i)){
                res = (res | (1 << (31 - i)));
            }
        }
        return res;
    }
};