class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> parent(c + 1),rank(c + 1,0);
        for(int i = 0;i <= c;i++){
            parent[i] = i;
        }
        function<int(int)> find = [&](int num)->int{
            if(parent[num] == num) return num;
            return parent[num] = find(parent[num]);
        };
        auto Union = [&](int num1,int num2){
            int p1 = find(num1);
            int p2 = find(num2);
            if(p1 == p2) return;
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
        };
        for(auto& edge : connections){
            Union(edge[0],edge[1]);
        }
        vector<bool> online(c + 1,true);
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> map;
        for(int i = 1;i <= c;i++){
            int root = find(i);
            map[root].push(i);
        }
        vector<int> result;
        for(auto& query : queries){
            int type = query[0];
            int node = query[1];
            if(type == 1){
                if(online[node]){
                    result.push_back(node);
                }
                else{
                    int root = find(node);
                    while(!map[root].empty()){
                        int nn = map[root].top();
                        if(!online[nn]){
                            map[root].pop();
                        }
                        else{
                            result.push_back(nn);
                            break;
                        }
                    }
                    if(map[root].empty()){
                        result.push_back(-1);
                    }
                }
            }
            else{
                online[node] = false;
            }
        }
        return result;
    }
};