class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        using ll = long long;

        function<bool(ll)> feasible = [&](ll mid)->bool{

            int moves = k1 + k2;
            for(int i = 0;i < n;i++){

                ll diff = abs(nums1[i] - nums2[i]);
                if(mid < diff){
                    if(diff - mid > moves) return false;
                    moves -= (diff - mid);
                }
            }

            return true;
        };

        ll diff = INT_MAX;
        ll left = 0;
        ll right = 1e5 + 1;
        
        while(left <= right){
            ll mid = (left + right)/2;

            if(feasible(mid)){
                diff = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        int rest = k1 + k2;
        for(int i = 0;i < n;i++){
            ll currDiff = abs(nums1[i] - nums2[i]);

            if(currDiff > diff){
                rest -= (currDiff - diff);
            }
        }

        priority_queue<int> pq;
        for(int i = 0;i < n;i++){
            ll currDiff = abs(nums1[i] - nums2[i]);

            if(min(currDiff, diff) > 0)
                pq.push(min(currDiff, diff));
        }

        while(rest && !pq.empty()){
            int num = pq.top();pq.pop();

            if(num > 1)
                pq.push(num - 1);

            rest--;
        }

        ll res = 0;
        while(!pq.empty()){
            ll num = pq.top();pq.pop();
            res += num * num;
        }

        return res;
    }
};