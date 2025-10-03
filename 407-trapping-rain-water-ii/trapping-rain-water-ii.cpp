class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> visit(n,vector<int>(m,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i = 0;i < n;i++){
            pq.push({heightMap[i][0],i,0});
            visit[i][0] = true;
            pq.push({heightMap[i][m - 1],i,m - 1});
            visit[i][m - 1] = true;
        }
        for(int i = 1;i < m - 1;i++){
            pq.push({heightMap[0][i],0,i});
            visit[0][i] = true;
            pq.push({heightMap[n - 1][i],n - 1,i});
            visit[n - 1][i] = true;
        }
        int total = 0;
        int dirx[4] = {-1,1,0,0};
        int diry[4] = {0,0,-1,1};
        while(!pq.empty()){
            auto temp = pq.top();pq.pop();
            int h = temp[0];
            int x = temp[1];
            int y = temp[2];
            int minh = INT_MAX;
            for(int d = 0;d < 4;d++){
                int nx = x + dirx[d];
                int ny = y + diry[d];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && !visit[nx][ny]){
                    int nh = heightMap[nx][ny];
                    if(nh < h){
                        total += h - nh;
                    }
                    pq.push({max(nh,h),nx,ny});
                    visit[nx][ny]= true;
                }
            }
        }
        return total;
    }
};