class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int maxV = 0;
        int maxE = *max_element(nums.begin(),nums.end());

        if(maxE == 0) return 0;
        int len = log2(maxE);

        for (int b = 0; b <= len; b++) {

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