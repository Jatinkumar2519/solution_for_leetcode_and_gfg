class Solution {
public:
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        unordered_map<int,unordered_map<int,double>> dp;
        vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
        function<double(int,int)> solve = [&](int a,int b) -> double{
            if(a <= 0 && b <= 0) return 0.5;
            if(a <= 0) return 1;
            if(b <= 0) return 0;
            if(dp.count(a) && dp[a].count(b)) return dp[a][b];
            double prob = 0.0;
            for(auto& [num1,num2] : serves){
                prob += 0.25 * solve(a - num1,b - num2);
            }
            return dp[a][b] = prob;
        };
        return solve(n,n);
    }
};