class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto& a,auto& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();

        vector<vector<int>> arr;
        arr.push_back(intervals[0]);

        for(int i = 1;i < n;i++){
            if(arr.back()[1] < intervals[i][1]){
                arr.push_back(intervals[i]);
            }
        }

        return arr.size();
    }
};