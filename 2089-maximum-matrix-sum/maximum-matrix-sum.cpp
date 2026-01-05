class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        long long sum = 0;
        int minv = INT_MAX;
        int n = matrix.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                sum += abs(matrix[i][j]);
                count += (matrix[i][j] < 0);
                minv = min(minv,abs(matrix[i][j]));
            }
        }

        if(count % 2 == 0) return sum;

        return sum - 2 * minv;
    }
};