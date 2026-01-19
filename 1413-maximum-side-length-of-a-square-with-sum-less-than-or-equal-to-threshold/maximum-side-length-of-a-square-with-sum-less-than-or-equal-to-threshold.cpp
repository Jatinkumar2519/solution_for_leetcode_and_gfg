class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> prefix(n,vector<int>(m));
        for(int i = 0;i < n;i++){
            prefix[i][0] = mat[i][0];
            for(int j = 1;j < m;j++){
                prefix[i][j] = prefix[i][j - 1] + mat[i][j];
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 1;j < n;j++){
                prefix[j][i] += prefix[j - 1][i];
            }
        }

        auto getSum = [&](int x,int y,int k){
            int x2 = x + k - 1;
            int y2 = y + k - 1;

            int sum = prefix[x2][y2];

            if(x > 0){
                sum -= prefix[x - 1][y2];
            }
            if(y > 0){
                sum -= prefix[x2][y - 1];
            }
            if(x > 0 && y > 0){
                sum += prefix[x - 1][y - 1];
            }

            return sum;
        };

        auto feasible = [&](int k){
            for(int i = 0;i <= n - k;i++){
                for(int j = 0;j <= m - k;j++){
                    if(getSum(i,j,k) <= threshold) return true;
                }
            }
            return false;
        };

        int left = 1;
        int right = min(n,m);

        int res = 0;
        while(left <= right){
            int mid = (left + right)/2;

            if(feasible(mid)){
                res = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return res;
    }
};