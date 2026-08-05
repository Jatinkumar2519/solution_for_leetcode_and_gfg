class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> visit(n);
        vector<vector<int>> graph(n);

        for(auto& edge : invocations){
            graph[edge[0]].push_back(edge[1]);
        }

        visit[k] = true;
        queue<int> q{{k}};

        while(!q.empty()){
            int node = q.front();q.pop();

            for(int nbr : graph[node]){
                if(visit[nbr]) continue;

                visit[nbr] = true;
                q.push(nbr);
            }
        }

        vector<int> notInf;
        vector<bool> done(n,false);

        for(int node = 0;node < n;node++){
            if(!visit[node]){

                notInf.push_back(node);
                q.push(node);

                done[node] = true;
            }
        }

        while(!q.empty()){
            int node = q.front();q.pop();
            if(visit[node]){
                vector<int> res;
                for(int i = 0;i < n;i++) res.push_back(i);

                return res;
            }

            for(int nbr : graph[node]){
                if(done[nbr]) continue;

                done[nbr] = true;
                q.push(nbr);
            }
        }

        return notInf;
    }
};