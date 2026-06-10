class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int K) {
        int n = nums.size();
        int len = sqrt(n) + 1;
        using ll = long long;

        vector<int> table_min(len,INT_MAX),table_max(len,INT_MIN);

        for(int i = 0;i < n;i++){
            table_min[i / len] = min(table_min[i / len],nums[i]);
            table_max[i / len] = max(table_max[i / len],nums[i]);
        }
        
        auto getValue = [&](int i,int j)->int{
            int minv = INT_MAX;
            int maxv = INT_MIN;

            for(int k = i;k <= j;){
                if(k % len == 0 && k + len < j){
                    minv = min(minv,table_min[k / len]);
                    maxv = max(maxv,table_max[k / len]);
                    k += len;
                }
                else{
                    minv = min(minv,nums[k]);
                    maxv = max(maxv,nums[k]);
                    k++;
                }
            }

            return maxv - minv;
        };
        
        ll res = 0;
        
        int maxv = INT_MIN;
        int minv = INT_MAX;

        priority_queue<tuple<int,int,int>> pq;

        for(int i = n - 1;i >= 0;i--){

            maxv = max(maxv,nums[i]);
            minv = min(minv,nums[i]);

            pq.push(make_tuple(maxv - minv,i,n - 1));
        }

        while(!pq.empty() && K > 0){
            auto [val,i,j] = pq.top();pq.pop();
            res += val;K--;

            if(i < j)
                pq.push(make_tuple(getValue(i,j - 1),i,j - 1));
        }

        return res;
    }
};