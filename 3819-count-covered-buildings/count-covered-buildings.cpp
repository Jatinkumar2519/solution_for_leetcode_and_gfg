class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> leftRow(n + 1,n + 1);
        vector<int> rightRow(n + 1,0);
        vector<int> leftCol(n + 1,n + 1);
        vector<int> rightCol(n + 1,0);
        for(auto& point : buildings){
            int x = point[0];
            int y = point[1];
            leftRow[x] = min(leftRow[x],y);
            rightRow[x] = max(rightRow[x],y);
            leftCol[y] = min(leftCol[y],x);
            rightCol[y] = max(rightCol[y],x);
        }
        auto check = [&](int x,int y){
            return (leftRow[x] < y && y < rightRow[x]) && (leftCol[y] < x && x < rightCol[y]);
        };
        int count = 0;
        for(auto& point : buildings){
            int x = point[0];
            int y = point[1];
            count += check(x,y);
        }
        return count;
    }
};