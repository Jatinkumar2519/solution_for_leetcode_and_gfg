class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dirx[] = {-1,1,0,0};
        int diry[] = {0,0,-1,1};
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        dis[0][0] = grid[0][0];
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty()){
            auto arr = pq.top();pq.pop();
            int x = arr[1];
            int y = arr[2];
            int h = arr[0];
            if(h > dis[x][y]){
                continue;
            }
            // dis[x][y] = h;
            for(int i = 0; i < 4;i++){
                int n_x = x + dirx[i];
                int n_y = y + diry[i];
                if(n_x >= 0 && n_y >= 0 && n_x < m && n_y < n){
                    int new_h = h + grid[n_x][n_y];
                    if(new_h < dis[n_x][n_y]){
                        dis[n_x][n_y] = new_h;
                        if(n_x == m - 1 && n_y == n - 1){
                            continue;
                        }
                        pq.push({new_h,n_x,n_y});
                    }
                }
            }
        }
        // cout<< dis[m - 1][n - 1];
        return dis[m - 1][n - 1] < health;
    }
};