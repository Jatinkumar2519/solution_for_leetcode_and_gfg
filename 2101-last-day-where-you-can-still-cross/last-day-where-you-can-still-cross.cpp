class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        auto feasible = [&](int mid){
            vector<vector<int>> grid(row,vector<int>(col,0));

            for(int day = 1;day <= mid;day++){
                grid[cells[day - 1][0] - 1][cells[day - 1][1] - 1] = 1;
            }

            vector<vector<bool>> visit(row,vector<bool>(col,false));

            int dirx[4] = {-1,1,0,0};
            int diry[4] = {0,0,-1,1};

            function<bool(int,int)> DFS = [&](int i,int j)->bool{
                if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 1 || visit[i][j]) return false;
                if(i == row - 1) return true;
                visit[i][j] = true;
                for(int d = 0;d < 4;d++){
                    if(DFS(i + dirx[d],j + diry[d])) return true;
                }
                return false;
            };

            for(int i = 0;i < col;i++){
                if(DFS(0,i)) return true;
            }
            return false;
        };

        int left = 1;
        int right = cells.size();
        int res = -1;

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