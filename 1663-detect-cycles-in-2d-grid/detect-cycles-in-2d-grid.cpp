class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> parent(n*m),rank(n*m,0);
        for(int i = 0;i < n * m;i++){
            parent[i] = i;
        }
        function<int(int)> find = [&](int num) -> int{
            if(parent[num] == num) return num;
            return parent[num] = find(parent[num]);
        };
        function<bool(int,int)> Union = [&](int n1,int n2) -> bool{
            int p1 = find(n1);
            int p2 = find(n2);
            if(p1 == p2) return true;
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
            return false;
        };
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(j + 1 < m && grid[i][j + 1] == grid[i][j]){
                    if(Union(i * m + j,i * m + (j + 1))) return true;
                }
                if(i + 1 < n && grid[i + 1][j] == grid[i][j]){
                    if(Union(i * m + j,(i + 1) * m + j)) return true;
                }
            }
        }
        return false;
    }
};