class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> visit(n,false);

        for(int i = 0;i < n;i++){
            if(!visit[i]){
                queue<pair<int,int>> q;
                q.push({i,-1});

                vector<int> depth(n,0);

                while(!q.empty()){
                    auto [node,par] = q.front();q.pop();

                    visit[node] = true;

                    for(int nn : graph[node]){
                        if(nn == par) continue;
                        if(visit[nn]){
                            if((depth[node] + depth[nn] + 1) % 2 == 1) return false;
                            continue;
                        } 
                        
                        depth[nn] = depth[node] + 1;
                        q.push({nn,node});
                    }
                }
            }
        }

        return true;
    }
};