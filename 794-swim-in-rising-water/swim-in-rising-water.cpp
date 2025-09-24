class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,-1,1};
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        dp[0][0] = grid[0][0];
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto temp = pq.top();pq.pop();
            int cost = temp[0];
            int x = temp[1];
            int y = temp[2];
            if(dp[x][y] < cost) continue;
            for(int d = 0;d < 4;d++){
                int nx = x + dirx[d];
                int ny = y + diry[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < n){
                    int newcost = max(cost,grid[nx][ny]);
                    if(dp[nx][ny] > newcost){
                        dp[nx][ny] = newcost;
                        pq.push({newcost,nx,ny});
                    }
                }
            }
        }
        return dp[n - 1][n - 1];
    }
};