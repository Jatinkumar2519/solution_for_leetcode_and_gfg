class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;

        vector<int> dp(n,0);

        for(int i = 1;i < n;i++){
            dp[i] = dp[i - 1] + 1;
        }

        vector<vector<int>> graph(n);
        for(int i = 0;i + 1 < n;i++){
            graph[i].push_back(i + 1);
        }

        for(auto& query : queries){
            int u = query[0];
            int v = query[1];

            dp[v] = min(dp[v],dp[u] + 1);
            graph[u].push_back(v);

            for(int node = 0;node < n;node++){
                for(int nn : graph[node]){
                    dp[nn] = min(dp[nn],dp[node] + 1);
                }
            }

            result.push_back(dp[n - 1]);
        }
        return result;
    }
};