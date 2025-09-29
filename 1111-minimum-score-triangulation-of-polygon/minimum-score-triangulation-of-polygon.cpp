class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        map<int,int> dp;
        int n = values.size();
        function<int(int,int)> solve = [&](int i,int j)-> int{
            if(i + 2 > j) return 0;
            if(i + 2 == j) return values[i] * values[i + 1] * values[i + 2];
            int key = i * n + j;
            if(dp.count(key)) return dp[key];
            int minv = INT_MAX;
            for(int k = i + 1;k < j;k++){
                minv = min(minv,values[i] * values[j] * values[k] + solve(i,k) + solve(k,j));
            }
            return dp[key] = minv;
        };
        return solve(0,n - 1);
    }
};