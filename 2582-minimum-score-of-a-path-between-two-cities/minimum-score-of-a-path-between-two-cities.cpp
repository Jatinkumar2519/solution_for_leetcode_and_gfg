class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // approach - DSU
        vector<int> parent(n),rank(n);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }

        function<int(int)> find = [&](int node)->int{
            if(parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        };

        auto Union = [&](int node1,int node2){
            int par1 = find(node1);
            int par2 = find(node2);

            if(par1 == par2) return;

            if(rank[par1] > rank[par2]){
                parent[par2] = par1;
            }
            else if(rank[par1] < rank[par2]){
                parent[par1] = par2;
            }
            else{
                parent[par2] = par1;
                rank[par1]++;
            }
        };

        for(auto& road : roads){
            Union(road[0] - 1,road[1] - 1);
        }
        
        if(find(0) != find(n - 1)) return -1;

        int par = find(0);
        int minv = INT_MAX;

        for(auto& edge : roads){
            if(find(edge[0] - 1) == par && find(edge[1] - 1) == par){
                minv = min(minv,edge[2]);
            }
        }

        return minv;
    }
};