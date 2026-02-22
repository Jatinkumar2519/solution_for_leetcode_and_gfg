class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;
        int maxv = 0;

        for(int i = 0;i < 32;i++){
            if(n & (1 << i)){
                if(prev != -1)
                    maxv = max(maxv,i - prev);
                prev = i;
            }
        }

        return maxv;
    }
};