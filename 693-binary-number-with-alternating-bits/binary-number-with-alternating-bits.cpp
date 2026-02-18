class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long temp = 0;
        int flag = 1;

        while(temp < n){
            temp = temp << 1;

            if(flag){
                temp = (temp | 1);
            }

            flag = 1 - flag;
        }

        return temp == n;
    }
};