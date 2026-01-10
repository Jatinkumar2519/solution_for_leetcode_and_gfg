class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dirx[4] = {-1,0,1,0};
        int diry[4] = {0,-1,0,1};

        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> solve = [&](int i,int j){
            if(dp[i][j] != -1) return dp[i][j];
            int maxv = 0;
            for(int d = 0;d < 4;d++){
                int nx = i + dirx[d];
                int ny = j + diry[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                    if(matrix[i][j] < matrix[nx][ny]){
                        maxv = max(maxv,1 + solve(nx,ny));
                    }
                }
            }
            return dp[i][j] = maxv;
        };


        int maxPath = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                maxPath = max(maxPath,1 + solve(i,j));
            }
        }
        return maxPath;
    }
};