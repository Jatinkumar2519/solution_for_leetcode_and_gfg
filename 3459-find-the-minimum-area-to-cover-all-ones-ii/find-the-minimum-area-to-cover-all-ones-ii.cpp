class Solution {
public:
    int Area(vector<vector<int>>& grid,int u,int d,int l,int r){
        int down = 0;
        int right = 0;
        int up = grid.size();
        int left = grid[0].size();
        for(int i = u;i <= d;i++){
            for(int j = l;j <= r;j++){
                if(grid[i][j] == 0) continue;
                up = min(up,i);
                left = min(left,j);
                down = max(down,i);
                right = max(right,j);
            }
        }
        return up <= down ? (down - up + 1) * (right - left + 1) : INT_MAX/3;
    }
    vector<vector<int>> rotate(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res[m - j - 1][i] = grid[i][j];
            }
        }
        return res;
    }
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int res = n * m;
        for(int i = 0;i + 1 < n;i++){
            for(int j = 0;j + 1 < m;j++){
                res = min(res,Area(grid,0,i,0,m - 1) + Area(grid,i + 1,n - 1,0,j) + Area(grid,i + 1,n - 1,j + 1,m - 1));
                res = min(res,Area(grid,0,i,0,j) + Area(grid,0,i,j + 1,m - 1) + Area(grid,i + 1,n - 1,0,m - 1));
            }
        }
        for(int i = 0;i + 2 < n;i++){
            for(int j = i + 1;j + 1 < n;j++){
                res = min(res,Area(grid,0,i,0,m - 1) + Area(grid,i + 1,j,0,m - 1) + Area(grid,j + 1,n - 1,0,m - 1));
            }
        }
        return res;
    }
    int minimumSum(vector<vector<int>>& grid) {
        /*
        case1 : _______
               |   |   |
               ---------
               |_______|
        case2 : _______
               |       |
               ---------
               |___|___|
        case3 : _______
               |   |   |
               |   |----
               |___|___|
        case4 : _______
               |   |   |
               ----|   |
               |___|___|
        case5 : ___________
               |   |   |   |
               |   |   |   |
               |___|___|___|
        case6 : __________
               |          |
               |----------|
               |          |
               |----------|
               |__________|
        */
        vector<vector<int>> reversed = rotate(grid);
        return min(solve(grid),solve(reversed));
    }
};