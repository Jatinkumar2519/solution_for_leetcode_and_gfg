class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int count = 0;
        int n = intervals.size();
        vector<int> need(n,2);
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(int i = n - 1;i >= 0;i--){
            int s = intervals[i][0];
            int e = intervals[i][1];
            int m = need[i];
            for(int p = s;p < s + m;p++){
                for(int j = 0;j <= i;j++){
                    if(need[j] > 0 && p <= intervals[j][1]){
                        need[j]--;
                    }
                }
                count++;
            }
        }
        return count;
    }
};