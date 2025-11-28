class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int sum = 0;
        int count = 0;
        function<int(int,int)> solve = [&](int node,int par)->int{
            int sum = values[node] % k;
            for(int nn : graph[node]){
                if(par == nn) continue;
                sum = (sum + solve(nn,node)) % k;
            }
            if(sum == 0) count++;
            return sum;
        };
        solve(0,-1);
        return count;
    }
};