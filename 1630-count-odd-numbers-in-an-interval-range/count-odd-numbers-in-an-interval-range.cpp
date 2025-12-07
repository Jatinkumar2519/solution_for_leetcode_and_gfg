class Solution {
public:
    int countOdds(int low, int high) {
        high++;
        return high/2 - low/2;
    }
};