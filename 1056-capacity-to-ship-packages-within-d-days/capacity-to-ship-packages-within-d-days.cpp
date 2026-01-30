class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        auto feasible = [&](int capacity){
            int need = 1;
            int sum = 0;

            for(int i = 0;i < n;i++){
                if(sum + weights[i] > capacity){
                    need ++;
                    sum = 0;
                }
                sum += weights[i];
            }

            return need <= days;
        };

        int left = *max_element(weights.begin(),weights.end());
        int right = accumulate(weights.begin(),weights.end(),0);

        int res = left;
        while(left <= right){
            int mid = (left + right) / 2;

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