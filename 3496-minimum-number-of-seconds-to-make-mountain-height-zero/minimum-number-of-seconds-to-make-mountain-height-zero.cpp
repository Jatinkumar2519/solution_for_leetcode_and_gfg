class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        auto feasible = [&](long long mid){
            int height = mountainHeight;

            for(int i = 0;i < n;i++){
                long long num = 1;
                long long time = workerTimes[i];

                while(time <= mid && height > 0){
                    num++;height--;
                    time += num * workerTimes[i]; 
                }

                if(height == 0) return true;
            }
            return false;
        };

        long long left = 1;
        long long right = LLONG_MAX/2;

        long long res = -1;

        while(left <= right){
            long long mid = (left + right)/2;

            if(feasible(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return res;
    }
};