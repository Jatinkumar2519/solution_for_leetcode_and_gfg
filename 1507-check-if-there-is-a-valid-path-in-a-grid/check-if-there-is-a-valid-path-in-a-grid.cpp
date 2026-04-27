class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dirx[4] = {-1,0,1,0};
        int diry[4] = {0,1,0,-1};

        vector<vector<unordered_set<int>>> allowed(7,vector<unordered_set<int>>(4));
        allowed[1][1] = {1,3,5};
        allowed[1][3] = {1,4,6};

        allowed[2][0] = {2,3,4};
        allowed[2][2] = {2,5,6};

        allowed[3][2] = {2,5,6};
        allowed[3][3] = {1,4,6};

        allowed[4][1] = {1,3,5};
        allowed[4][2] = {2,5,6};

        allowed[5][0] = {2,3,4};
        allowed[5][3] = {1,4,6};

        allowed[6][0] = {2,3,4};
        allowed[6][1] = {1,3,5};

        vector<vector<bool>> visit(n,vector<bool>(m,false));

        function<bool(int,int)> solve = [&](int i,int j)->bool{
            if(i == n - 1 && j == m - 1) return true;
            visit[i][j] = true;

            for(int d = 0;d < 4;d++){
                int nx = i + dirx[d];
                int ny = j + diry[d];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny]){
                    if(allowed[grid[i][j]][d].count(grid[nx][ny])){
                        if(solve(nx,ny)) return true;
                    }
                }
            }
            return false;
        };

        return solve(0,0);
    }
};