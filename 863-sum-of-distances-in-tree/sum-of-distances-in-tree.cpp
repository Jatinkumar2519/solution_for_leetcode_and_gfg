class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int total = 0;
        vector<int> size(n);

        function<int(int,int,int)> dfs = [&](int node,int par,int d)->int{
            total += d;
            size[node] = 1;

            for(int nn : graph[node]){
                if(nn == par) continue;

                size[node] += dfs(nn,node,d + 1);
            }

            return size[node];
        };
        dfs(0,-1,0);

        vector<int> result(n);

        function<void(int,int,int)> solve = [&](int node,int par,int curr){
            result[node] = curr;

            for(auto nn : graph[node]){
                if(nn == par) continue;

                solve(nn,node,curr + n - 2 * size[nn]);
            }
        };
        solve(0,-1,total);

        return result;
    }
};