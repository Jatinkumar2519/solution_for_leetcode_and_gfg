class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n == 1 || (n > 0 && __builtin_popcount(n) == 1);
    }
};