class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();
        for(int i = 0;i < n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = 0;j < n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(i == j || !(x1 <= x2 && y1 >= y2)) continue;
                if(n == 2){
                    count++;
                    continue;
                }
                bool ok = true;
                for(int k = 0;k < n;k++){
                    if(k == i || k == j) continue;
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    bool containX = (x1 <= x3 && x3 <= x2);
                    bool containY = (y1 >= y3 && y3 >= y2);
                    if(containX && containY){
                        ok = false;
                        break;
                    }
                }
                if(ok) count++;
            }
        }
        return count;
    }
};