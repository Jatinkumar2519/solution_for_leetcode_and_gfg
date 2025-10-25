class Solution {
public:
    int totalMoney(int n) {
        int full_week = n / 7;
        int rem_days = n % 7;
        int total = full_week * 28 + ((full_week - 1) * (full_week))/2 * 7;
        for(int i = 1;i <= rem_days;i++) total += full_week + i;
        return total;
    }
};