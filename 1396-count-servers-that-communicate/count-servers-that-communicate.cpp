class Solution {
public:
    int BFS(vector<vector<int>> grid,int in1,int in2,int m,int n,vector<vector<int>>& visit){
        int dirx[] = {1,-1,0,0};
        int diry[] = {0,0,-1,1};
        queue<pair<int,int>> q;
        visit[in1][in2] = 1;
        int count = 1;
        q.push({in1,in2});
        while(!q.empty()){
            auto [x,y] = q.front();q.pop();
            for(int i = 0; i < m;i++){
                if(grid[i][y] && !visit[i][y]){
                    visit[i][y] = 1;
                    q.push({i,y});
                    count++;
                }
            }
            for(int i = 0; i < n;i++){
                if(grid[x][i] && !visit[x][i]){
                    visit[x][i] = 1;
                    q.push({x,i});
                    count++;
                }
            }
        }
        return count == 1 ? 0 : count;
    } 
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!visit[i][j] && grid[i][j]){
                    ans += BFS(grid,i,j,m,n,visit);
                }
            }
        }
        return ans;
    }
};