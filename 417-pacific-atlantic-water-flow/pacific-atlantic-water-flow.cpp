class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    vector<vector<int>> grid;
    vector<vector<bool>> visit;
    vector<int> dirx = {-1,1,0,0};
    vector<int> diry = {0,0,1,-1};
    void solve(int x,int y){
        dp[x][y]++;
        visit[x][y] = true;
        for(int d = 0;d < 4;d++){
            int nx = x + dirx[d];
            int ny = y + diry[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[x][y] <= grid[nx][ny]){
                if(!visit[nx][ny]){
                    solve(nx,ny);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        grid = heights;
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> result;
        dp.resize(n,vector<int>(m,0));
        visit.resize(n,vector<bool>(m,false));
        for(int i = 0;i < n;i++){
            if(!visit[i][0]){
                solve(i,0);
            }
        }
        for(int i = 0;i < m;i++){
            if(!visit[0][i]){
                solve(0,i);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                visit[i][j] = false;
            }
        }
        for(int i = 0;i < n;i++){
            if(!visit[i][m - 1]){
                solve(i,m - 1);
            }
        }
        for(int i = 0;i < m;i++){
            if(!visit[n - 1][i]){
                solve(n - 1,i);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(dp[i][j] == 2){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};