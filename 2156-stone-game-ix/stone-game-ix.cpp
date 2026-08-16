class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();

        int freq[3] = {0};
        for (int num : stones)
            freq[num % 3]++;

        if(freq[0] == n) return false;
        if(freq[0] % 2 == 0) return (freq[1] > 0 && freq[2] > 0);
        return abs(freq[1] - freq[2]) > 2;
    }
};