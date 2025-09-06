class Solution {
public:
    struct DSU{
        vector<int> parent,rank;
        DSU(int n){
            rank.resize(n+1);
            parent.resize(n+1);
            for(int i = 1;i <= n;i++){
                parent[i] = i;
            }
        }
        int find(int num){
            if(parent[num] == num) return num;
            return parent[num] = find(parent[num]);
        }
        bool Union(int n1,int n2){
            int p1 = find(n1);
            int p2 = find(n2);
            if(p1 == p2) return false;
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
            }
            else if(rank[p1] < rank[p2]){
                parent[p1] = p2;
            }
            else{
                rank[p1]++;
                parent[p2] = p1;
            }
            return true;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU bob(n);
        DSU alice(n);
        int count = 0;
        sort(edges.begin(),edges.end(),greater<vector<int>>());
        for(auto& edge : edges){
            int t = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(t == 1){
                if(!alice.Union(u,v)) count++;
            }
            else if(t == 2){
                if(!bob.Union(u,v)) count++;
            }
            else{
                if(!alice.Union(u,v) || !bob.Union(u,v)) count++;
            }
        }
        set<int> components;
        for(int i = 1;i <= n;i++){
            components.insert(bob.find(i));
        }
        if(components.size() > 1) return -1;
        components.clear();
        for(int i = 1;i <= n;i++){
            components.insert(alice.find(i));
        }
        if(components.size() > 1) return -1;
        return count;
    }
};