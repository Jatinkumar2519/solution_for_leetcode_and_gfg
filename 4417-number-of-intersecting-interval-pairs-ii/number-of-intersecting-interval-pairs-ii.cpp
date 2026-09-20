class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(),intervals.end(),[&](auto& a,auto& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        long long count = 0;
        for(int i = n - 1;i >= 0;i--){
            int y = intervals[i][1];

            int idx = i;
            int left = i;
            int right = n - 1;

            while(left <= right){
                int mid = (left + right)/2;

                if(y >= intervals[mid][0]){
                    idx = mid;
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            count = count + (idx - i);
        }

        return count;
    }
};