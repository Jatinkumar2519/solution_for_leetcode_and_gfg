class Solution {
public:
    int smallestNumber(int n, int t) {
    
        auto getProd = [&](int num)->int{
            int res = 1;
            while(num > 0){
                res = res * (num % 10);
                num /= 10;
            }

            return res;
        };

        for(int num = n;;num++){
            if(getProd(num) % t == 0) return num;
        }
        return -1;
    }
};