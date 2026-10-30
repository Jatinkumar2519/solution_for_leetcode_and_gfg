class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto &e : edges)
            graph[e[0]].push_back({e[1], e[2]});

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        dist[0][1] = 0;
        pq.push({0, 1, 0});

        while (!pq.empty()) {
            auto [cst, cnt, node] = pq.top();pq.pop();

            if (dist[node][cnt] < cst)
                continue;

            if (node == n - 1)
                return cst;

            for (auto& [nbr, edgeWt] : graph[node]) {

                int newCst = cst + edgeWt;
                int newCnt = (labels[node] == labels[nbr]) ? cnt + 1 : 1;

                if(newCnt <= k && dist[nbr][newCnt] > newCst){

                    dist[nbr][newCnt] = newCst;
                    pq.push({newCst, newCnt, nbr});
                }
            }
        }

        return -1;
    }
};