class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        auto isPrime = [&](int num){
            if(num <= 1) return false;
            for(int i = 2;i * i <= num;i++){
                if(num % i == 0) return false;
            }
            return true;
        };

        int count = 0;
        for(int num = left;num <= right;num++){
            int bit = __builtin_popcount(num);

            if(bit > 2 && bit % 2 == 0) continue;
            count += isPrime(bit);
        }

        return count;
    }
};