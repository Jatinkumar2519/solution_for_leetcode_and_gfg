class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> rowSum(n,vector<int>(m)),colSum(n,vector<int>(m));

        for(int i = 0;i < n;i++){
            int sum = 0;
            for(int j = 0;j < m;j++){
                sum += grid[i][j];
                rowSum[i][j] = sum;
            }
        }

        for(int i = 0;i < m;i++){
            int sum = 0;
            for(int j = 0;j < n;j++){
                sum += grid[j][i];
                colSum[j][i] = sum;
            }
        }

        int maxv = 1;
        for(int k = 2;k <= min(n,m);k++){
            for(int i = 0;i <= n - k;i++){
                for(int j = 0;j <= m - k;j++){
                    unordered_set<int> total;
                    int dia1 = 0,dia2 = 0;
                    for(int p = 0;p < k;p++){
                        int row = (j == 0) ? rowSum[i + p][j + k - 1] : rowSum[i + p][j + k - 1] - rowSum[i + p][j - 1];
                        int col = (i == 0) ? colSum[i + k - 1][j + p] : colSum[i + k - 1][j + p] - colSum[i - 1][j + p];

                        dia1 += grid[i + p][j + p];
                        dia2 += grid[i + p][j + (k - p - 1)];

                        total.insert(row);
                        total.insert(col);
                    }

                    total.insert(dia1);
                    total.insert(dia2);

                    if(total.size() == 1){
                        maxv = max(maxv,k);
                    }
                }
            }
        }

        return maxv;
    }
};