class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxV = 0;
        for (int b = 0; b < 32; b++) {

            int zero = 0, one = 0;
            for (int num : nums) {
                if (num & (1 << b))
                    one++;
                else
                    zero++;
            }

            if (one == 0)
                continue;
            if (one % 2 == 0)
                one--;

            maxV = max(maxV, one + zero);
        }

        return maxV;
    }
};