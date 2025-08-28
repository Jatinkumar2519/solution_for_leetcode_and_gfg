class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager,vector<int>& informTime) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] == -1)
                continue;
            graph[i].push_back(manager[i]);
            graph[manager[i]].push_back(i);
        }
        function<int(int, int)> solve = [&](int node, int par) {
            int time = 0;
            for (int nn : graph[node]) {
                if (par == nn)
                    continue;
                time = max(time, solve(nn, node));
            }
            return time + informTime[node];
        };
        return solve(headID, -1);
    }
};