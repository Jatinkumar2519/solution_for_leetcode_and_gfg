class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> visit(n,vector<bool>((1 << n),false));
        queue<pair<int,int>> q;
        for(int i = 0;i < n;i++){
            q.push({i,(1 << i)});
            visit[i][(1 << i)] = true;
        }
        int time = 0;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto [node,mask] = q.front();q.pop();
                if(__builtin_popcount(mask) == n) return time;
                for(auto& nn : graph[node]){
                    int newmask = (mask | (1 << nn));
                    if(visit[nn][newmask]) continue;
                    visit[nn][newmask] = true;
                    q.push({nn,newmask});
                }
            }
            time++;
        }
        return time;
    }
};