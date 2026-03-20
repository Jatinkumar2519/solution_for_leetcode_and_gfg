class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m - k + 1,vector<int>(n - k + 1));
        for(int i = 0;i <= m - k;i++){
            for(int j = 0;j <= n - k;j++){

                set<int> visit;
                for(int p = i;p < i + k;p++){
                    for(int q = j;q < j + k;q++){
                        visit.insert(grid[p][q]);
                    }
                }
                vector<int> arr(visit.begin(),visit.end());

                int mind = INT_MAX;
                for(int x = 1;x < arr.size();x++){
                    mind = min(mind,abs(arr[x - 1] - arr[x]));
                }
                
                result[i][j] = (mind == INT_MAX) ? 0 : mind;
            }
        }
        return result;
    }
};