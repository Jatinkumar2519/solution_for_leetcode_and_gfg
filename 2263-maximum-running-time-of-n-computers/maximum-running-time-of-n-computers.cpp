class Solution {
public:
    long long maxRunTime(int computers, vector<int>& batteries) {
        using ll = long long;
        
        ll total = 0;
        for (int b : batteries) {
            total += b;
        }

        ll left = 0, right = total / computers;
        ll result = 0;

        auto canRun = [&](ll t) {
            long long sum = 0;
            for (int b : batteries) {
                sum += min<ll>(b, t);
                if (sum >= t * computers) return true; 
            }
            return sum >= t * computers;
        };

        while (left <= right) {
            ll mid = left + (right - left) / 2;

            if (canRun(mid)) {
                result = mid;
                left = mid + 1;   
            } else {
                right = mid - 1;  
            }
        }

        return result;
    }
};
