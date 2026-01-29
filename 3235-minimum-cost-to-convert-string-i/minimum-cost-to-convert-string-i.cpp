class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> grid(26,vector<long long>(26,INT_MAX));
        for(int i = 0; i < cost.size();i++){
            int start = original[i] - 'a';
            int end = changed[i] - 'a';
            long long wt = cost[i];
            grid[start][end] = min(grid[start][end],wt);
            // grid[end][start] = min(grid[start][end],wt);
        }
        for(int k = 0; k < 26;k++){
            for(int i = 0; i < 26;i++){
                for(int j = 0; j < 26;j++){
                    if(grid[i][k] != INT_MAX && grid[k][j] != INT_MAX){
                        grid[i][j] = min(grid[i][j],grid[i][k] + grid[k][j]);
                    }
                }
            }
        }
        long long sum = 0;
        for(int i = 0; i < source.length();i++){
            int start = source[i] - 'a';
            int end = target[i] - 'a';
            if (start != end) { 
                if (grid[start][end] == INT_MAX) { 
                    return -1;
                } 
                sum += grid[start][end];
            }
        }
        return sum;
    }
};