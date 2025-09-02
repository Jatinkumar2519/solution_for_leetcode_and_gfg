class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int,int> map;
        for(int i = 0;i < n;i++){
            map[quiet[i]] = i;
        }
        vector<vector<int>> graph(n);
        for(auto edge : richer){
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
        }
        vector<int> dp(n,-1);
        function<int(int)> solve= [&](int node) -> int{
            if(dp[node] != -1) return dp[node];
            int res = quiet[node];
            for(int nn : graph[node]){
                res = min(res,solve(nn));
            }
            return dp[node] = res;
        };
        for(int i = 0;i < n;i++){
            if(dp[i] == -1)
                solve(i);
        }
        for(int i = 0;i < n;i++){
            dp[i] = map[dp[i]];
        }
        return dp;
    }
};