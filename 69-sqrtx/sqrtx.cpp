class Solution {
public:
    int mySqrt(int x) {
        long long left = 0;
        long long right = x;

        while(left < right){
            long long mid = (left + right)/2 + 1;

            if(mid * mid <= x){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }

        return left;
    }
};