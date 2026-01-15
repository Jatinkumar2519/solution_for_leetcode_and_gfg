class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto feasible = [&](long long mid){
            int time = 0;
            for(auto& num : piles){

                time += (int)num / mid;
                if(num % mid != 0) time++;

                if(time > h) return false;
            }
            return true;
        };

        long long left = 1;
        long long right = accumulate(piles.begin(),piles.end(),0LL);

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