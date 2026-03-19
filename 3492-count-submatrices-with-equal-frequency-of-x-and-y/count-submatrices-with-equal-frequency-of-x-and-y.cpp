class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix_X(n,vector<int>(m));
        vector<vector<int>> prefix_Y(n,vector<int>(m));

        for(int i = 0;i < n;i++){

            prefix_X[i][0] = (grid[i][0] == 'X');
            prefix_Y[i][0] = (grid[i][0] == 'Y');
    
            for(int j = 1;j < m;j++){

                prefix_X[i][j] = prefix_X[i][j - 1] + (grid[i][j] == 'X');
                prefix_Y[i][j] = prefix_Y[i][j - 1] + (grid[i][j] == 'Y');
            }
        }

        for(int j = 0;j < m;j++){
            for(int i = 1;i < n;i++){
                prefix_X[i][j] += prefix_X[i - 1][j];
                prefix_Y[i][j] += prefix_Y[i - 1][j];
            }
        }

        auto check = [&](int x1,int y1,int x2,int y2){
            int sum1 = prefix_X[x2][y2];
            int sum2 = prefix_Y[x2][y2];

            if(y1 > 0){
                sum1 -= prefix_X[x2][y1 - 1];
                sum2 -= prefix_Y[x2][y1 - 1];
            }
            if(x1 > 0){
                sum1 -= prefix_X[x1 - 1][y2];
                sum2 -= prefix_Y[x1 - 1][y2];
            }
            if(x1 > 0 && y1 > 0){
                sum1 += prefix_X[x1 - 1][y1 - 1];
                sum2 += prefix_Y[x1 - 1][y1 - 1];
            }

            return sum1 > 0 && sum1 == sum2;
        };

        int count = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                count += check(0,0,i,j);
            }
        }

        return count;
    }
};