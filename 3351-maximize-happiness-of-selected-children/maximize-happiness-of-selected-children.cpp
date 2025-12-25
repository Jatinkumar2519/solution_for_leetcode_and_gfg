class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long sum = 0;
        int minus = 0;
        for(int i = 0;i < k;i++){
            sum += max(0,happiness[i] - minus);
            minus++;
        }
        return sum;
    }
};