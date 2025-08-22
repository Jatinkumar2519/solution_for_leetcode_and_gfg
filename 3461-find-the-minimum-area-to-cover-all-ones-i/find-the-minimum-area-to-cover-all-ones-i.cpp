class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int down = 0;
        int right = 0;
        int up = n - 1;
        int left = m - 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(grid[i][j] == 1){
                    up = min(up,i);
                    left = min(left,j);
                    down = max(down,i);
                    right = max(right,j);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};