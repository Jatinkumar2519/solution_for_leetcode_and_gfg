class Solution {
public:
    int findShortestCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int mincycle = INT_MAX;
        for(int i = 0;i < V;i++){
            vector<int> dist(V,-1),parent(V,-1);
            dist[i] = 0;
            queue<int> q{{i}};
            while(!q.empty()){
                int node = q.front();q.pop();
                for(int nn : graph[node]){
                    if(dist[nn] == -1){
                        dist[nn] = dist[node] + 1;
                        parent[nn] = node;
                        q.push(nn);
                    }
                    else if(parent[node] != nn){
                        mincycle = min(mincycle,dist[nn] + dist[node] + 1);
                    }
                }
            }
        }
        return (mincycle == INT_MAX) ? -1 : mincycle;
    }
};