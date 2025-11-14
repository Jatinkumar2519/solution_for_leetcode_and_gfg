class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n + 1,vector<int>(n + 1,0));
        for(auto& query : queries){
            int x1 = query[0];
            int y1 = query[1];
            int x2 = query[2];
            int y2 = query[3];
            mat[x1][y1] += 1;
            mat[x1][y2 + 1] -= 1;
            mat[x2 + 1][y1] -= 1;
            mat[x2 + 1][y2 + 1] += 1;
        }
        for(int i = 0;i <= n;i++){
            int sum = 0;
            for(int j = 0;j <= n;j++){
                sum += mat[i][j];
                mat[i][j] = sum;
            }
        }
        for(int i = 0;i <= n;i++){
            int sum = 0;
            for(int j = 0;j <= n;j++){
                sum += mat[j][i];
                mat[j][i] = sum;
            }
        }
        vector<vector<int>> result(n,vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                result[i][j] = mat[i][j];
            }
        }
        return result;
    }
};