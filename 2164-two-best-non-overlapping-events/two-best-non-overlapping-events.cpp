class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        vector<int> suffix(n);
        sort(events.begin(),events.end());
        suffix[n - 1] = events[n - 1][2];
        for(int i = n - 2;i >= 0;i--){
            suffix[i] = max(suffix[i + 1],events[i][2]);
        }
        int maxv = 0;
        for(int i = 0;i < n;i++){
            int left = i + 1;
            int right = n;
            int target = events[i][1];
            while(left < right){
                int mid = (left + right)/2;
                if(target >= events[mid][0]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            int sum = events[i][2];
            if(left < n){
                sum += suffix[left];
            }
            maxv = max(maxv,sum);
        }
        return maxv;
    }
};