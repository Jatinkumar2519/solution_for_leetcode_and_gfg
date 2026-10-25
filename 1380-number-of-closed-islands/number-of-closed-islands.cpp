class Solution {
public:
    bool BFS(vector<vector<int>>& grid,int i1,int i2,int m,int n,vector<vector<int>>& visit){
        int dirx[] = {0,0,-1,1};
        int diry[] = {-1,1,0,0};
        visit[i1][i2] = 1;
        queue<pair<int,int>> q;
        q.push({i1,i2});
        bool flag = true;
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            for(int i = 0; i < 4;i++){
                int n_x = x + dirx[i];
                int n_y = y + diry[i];
                if(n_x >= 0 && n_y >= 0 && n_x < m && n_y < n){
                    if(!grid[n_x][n_y] && !visit[n_x][n_y]){
                        q.push({n_x,n_y});
                        visit[n_x][n_y] = 1;
                    }
                }
                else{
                    flag = false;
                }
            }
        }
        return flag;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!visit[i][j] && !grid[i][j]){
                    if(BFS(grid,i,j,m,n,visit)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};