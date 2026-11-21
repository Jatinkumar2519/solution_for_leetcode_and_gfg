class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> tree(n);

        for(int i = 1;i < n;i++){
            tree[parent[i]].push_back(i);
        }

        vector<stack<int>> map(26,stack<int>());
        function<void(int)> solve = [&](int node)->void{

            int ch = s[node] - 'a';
            if(!map[ch].empty()){
                int ansc = map[ch].top();
                parent[node] = ansc;
            }

            map[ch].push(node);

            for(int nbr : tree[node]){
                solve(nbr);
            }

            map[ch].pop();
        };
        solve(0);

        tree = vector<vector<int>>(n);
        for(int i = 1;i < n;i++){
            tree[parent[i]].push_back(i);
        }
        
        vector<int> result(n);
        function<int(int)> DFS = [&](int node)->int{

            result[node] = 1;
            for(int nbr : tree[node]){
                result[node] += DFS(nbr);
            }

            return result[node];
        };
        DFS(0);

        return result;
    }
};