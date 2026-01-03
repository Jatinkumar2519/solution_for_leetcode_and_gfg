class Solution {
public:
    int numOfWays(int n) {
        long long same = 6;
        long long diff = 6;
        int mod = 1e9 + 7;

        for(int i = 1;i < n;i++){
            long long t_same = 3 * same + 2 * diff;
            long long t_diff = 2 * same + 2 * diff;
            same = t_same % mod;
            diff = t_diff % mod;
        }
        return (same + diff) % mod;
    }
};