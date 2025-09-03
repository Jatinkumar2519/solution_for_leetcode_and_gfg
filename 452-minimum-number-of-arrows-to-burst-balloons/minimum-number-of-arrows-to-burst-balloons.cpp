class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int count = 1;
        auto prev = points[0];
        for(int i = 1;i < n;i++){
            if(prev[1] >= points[i][0]){
                prev[0] = max(prev[0],points[i][0]);
                prev[1] = min(prev[1],points[i][1]);
            }
            else{
                prev = points[i];
                count ++;
            }
        }
        return count;
    }
};
/*
1,6 - 2,8 - 7,12 - 10,16
2,6 - 
*/