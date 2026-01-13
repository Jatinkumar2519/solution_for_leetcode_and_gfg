class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        auto feasible = [&](double mid) {
            double leftA = 0, rightA = 0;
            for (auto& p : squares) {
                double x = p[1], l = p[2];
                if (x < mid && mid < x + l) 
                    leftA += l * (mid - x);
                else if (x + l <= mid) 
                    leftA += l * l;
            }
            for (auto& p : squares) {
                double x = p[1], l = p[2];
                if (x < mid && mid < x + l) 
                    rightA += l * (x + l - mid);
                else if (mid <= x) 
                    rightA += l * l;
            }
            return leftA >= rightA;
        };

        double lo = 0, hi = -1e18;
        for (auto& p : squares) {
            hi = max(hi, (double)p[1] + p[2]);
        }

        double eps = 1e-5;
        while (abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (feasible(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};
