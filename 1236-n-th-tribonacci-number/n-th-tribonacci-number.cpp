class Solution {
public:
    int tribonacci(int n) {
        using ll = long long;

        function<vector<vector<ll>>(const vector<vector<ll>>&,
                                    const vector<vector<ll>>&)> mul =
            [&](const vector<vector<ll>>& A,
                const vector<vector<ll>>& B) {
                vector<vector<ll>> R(3, vector<ll>(3, 0));
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        for (int k = 0; k < 3; k++) {
                            R[i][j] = (R[i][j] +
                                      A[i][k] * B[k][j]);
                        }
                    }
                }
                return R;
            };

        function<vector<vector<ll>>(vector<vector<ll>>, ll)> power =
            [&](vector<vector<ll>> mat, ll p) {
                vector<vector<ll>> res = {
                    {1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}
                };

                while (p > 0) {
                    if (p & 1) res = mul(res, mat);
                    mat = mul(mat, mat);
                    p >>= 1;
                }
                return res;
            };

        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        vector<vector<ll>> M = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };

        auto R = power(M, n - 2);

        return (R[0][0] + R[0][1]);
    }
};
