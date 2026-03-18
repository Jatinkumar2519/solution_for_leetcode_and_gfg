class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i = 0;i < n;i++){
            prefix[i][0] = grid[i][0];
            for(int j = 1;j < m;j++){
                prefix[i][j] = prefix[i][j - 1] + grid[i][j];
            }
        }

        for(int j = 0;j < m;j++){
            for(int i = 1;i < n;i++){
                prefix[i][j] += prefix[i - 1][j];
            }
        }

        auto getSum = [&](int x1,int y1,int x2,int y2){
            int sum = prefix[x2][y2];

            if(y1 > 0){
                sum -= prefix[x2][y1 - 1];
            }
            if(x1 > 0){
                sum -= prefix[x1 - 1][y2];
            }
            if(x1 > 0 && y1 > 0){
                sum += prefix[x1 - 1][y1 - 1];
            }

            return sum <= k;
        };

        int count = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                count += getSum(0,0,i,j);
            }
        }

        return count;
    }
};