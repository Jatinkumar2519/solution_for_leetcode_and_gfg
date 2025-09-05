class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k = 1;
        while(true){
            long long num = num1 - static_cast<long long>(num2) * k;
            if(num < k) return -1;
            if(__builtin_popcountll(num) <= k) return k;
            k++;
        }
        return -1;
    }
};