class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});    
            graph[v].push_back({u, 2*w});    
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        using T = pair<long long,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        pq.push({0,0});

        while (!pq.empty()) {
            auto [d,u] = pq.top(); pq.pop();

            if (d > dist[u]) continue;
            for (auto [v,w] : graph[u]) {
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1] == LLONG_MAX ? -1 : (int)dist[n-1];
    }
};
