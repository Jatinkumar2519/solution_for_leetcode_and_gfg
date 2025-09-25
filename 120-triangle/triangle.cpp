class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle.back().size();
        int l = 2 * m;
        vector<vector<int>> matrix(n + 1,vector<int>(l + 1,INT_MAX));
        int space = 1;
        for(int i = n;i > 0;i--){
            int k = space;
            for(int j = 0;j < triangle[i - 1].size();j++){
                matrix[i][k] = triangle[i - 1][j];
                k += 2;
            }
            space++;
        }
        for(int i = 1;i <= n;i++){
            for(int j = 1;j < l;j++){
                if(matrix[i][j] == INT_MAX) continue;
                int minv = min(matrix[i - 1][j - 1],matrix[i - 1][j + 1]);
                matrix[i][j] += (minv == INT_MAX) ? 0 : minv;
            }
        }
        int res = INT_MAX;
        for(int i = 1;i < l;i++){
            res = min(res,matrix[n][i]);
        }
        return res;
    }
};