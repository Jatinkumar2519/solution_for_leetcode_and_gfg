class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        
        priority_queue<pair<int,int>> pq;
        pq.push({0,0});

        vector<int> dist(n,INT_MIN);
        dist[0] = 0;
        while(!pq.empty()){
            auto [cost,node] = pq.top();pq.pop();

            if(dist[node] > cost) continue;
            
            for(int i = node + 1;i < n;i++){
                int dif = nums[i] - nums[node];

                if(-target <= dif && dif <= target && cost + 1 > dist[i]){
                    dist[i] = cost + 1;
                    pq.push({cost + 1,i});
                }
            }
        }

        return (dist[n - 1] == INT_MIN ? -1 : dist[n - 1]);
    }
};