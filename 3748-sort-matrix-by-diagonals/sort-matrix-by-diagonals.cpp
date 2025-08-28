class Solution {
public:
    static bool cmp(int& a ,int& b){
        return a > b;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> graph(n*2 - 1);
        int j = 0;
        for(int i = n - 1;i >= 0;i--){
            int x = 0;int y = i;
            while(x < n && y < n){
                graph[j].push_back(grid[x][y]);
                x = x + 1;y = y + 1;
            }
            j++;
        }
        for(int i = 1;i < n;i++){
            int x = i;int y = 0;
            while(x < n && y < n){
                graph[j].push_back(grid[x][y]);
                x = x + 1;y = y + 1;
            }
            j++;
        }
        for(int i = 0;i < j;i++){
            if(i < n - 1){
                sort(graph[i].begin(),graph[i].end());
            }
            else{
                sort(graph[i].begin(),graph[i].end(),cmp);
            }
        }
        j = 0;
        for(int i = n - 1;i >= 0;i--){
            int x = 0;int y = i;
            int k = 0;
            while(x < n && y < n){
                grid[x][y] = graph[j][k++];
                x = x + 1;y = y + 1;
            }
            j++;
        }
        for(int i = 1;i < n;i++){
            int x = i;int y = 0;
            int k = 0;
            while(x < n && y < n){
                grid[x][y] = graph[j][k++];
                x = x + 1;y = y + 1;
            }
            j++;
        }
        return grid;
    }
};