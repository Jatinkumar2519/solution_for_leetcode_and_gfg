class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sum1 = 0,sum2 = 0;
        int i = 2;
        int count = 0;
        while(count < n){
            count++;
            sum1 += i;
            i += 2;
        }
        i = 1;
        count = 0;
        while(count < n){
            count++;
            sum2 += i;
            i += 2;
        }
        return __gcd(sum1,sum2);
    }
};