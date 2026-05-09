class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int l = 0;
        int r = m - 1;
        int u = 0;
        int d = n - 1;
        
        int t = min(n,m)/2;
        while(t--){
            vector<int> nums;
            vector<pair<int,int>> indices;

            for(int i = u;i <= d;i++){
                indices.push_back({i,l});
                nums.push_back(grid[i][l]);
            }
            l++;

            for(int i = l;i <= r;i++){
                indices.push_back({d,i});
                nums.push_back(grid[d][i]);
            }
            d--;

            for(int i = d;i >= u;i--){
                indices.push_back({i,r});
                nums.push_back(grid[i][r]);
            }
            r--;

            for(int i = r;i >= l;i--){
                indices.push_back({u,i});
                nums.push_back(grid[u][i]);
            }
            u++;

            int len = nums.size();
            int idx = k % len;

            for(int i = 0;i < len;i++){
                int id = (i - idx + len) % len;

                auto [u,v] = indices[i];
                grid[u][v] = nums[id];
            }
        }
        return grid;
    }
};