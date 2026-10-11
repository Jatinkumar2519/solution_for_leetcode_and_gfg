
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0] * nums[0];

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                sum += nums[i - 1] * nums[i - 1];

                int d = n / i;
                if (d != i) {
                    sum += nums[d - 1] * nums[d - 1];
                }
            }
        }

        if (n > 1) {
            sum += nums[n - 1] * nums[n - 1];
        }

        return sum;
    }
};
