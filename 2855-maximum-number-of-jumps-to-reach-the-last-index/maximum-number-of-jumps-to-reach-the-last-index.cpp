class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        // ***********Djkestra************

        // priority_queue<pair<int,int>> pq;
        // pq.push({0,0});

        // vector<int> dist(n,INT_MIN);
        // dist[0] = 0;
        // while(!pq.empty()){
        //     auto [cost,node] = pq.top();pq.pop();

        //     if(dist[node] > cost) continue;
            
        //     for(int i = node + 1;i < n;i++){
        //         int dif = nums[i] - nums[node];

        //         if(-target <= dif && dif <= target && cost + 1 > dist[i]){
        //             dist[i] = cost + 1;
        //             pq.push({cost + 1,i});
        //         }
        //     }
        // }

        // return (dist[n - 1] == INT_MIN ? -1 : dist[n - 1]);



        // *************dynamic programming (memoization)************

        // int dp[1001];
        
        // function<int(int)> solve = [&](int node)->int{
        //     if(node == n - 1) return 0;

        //     if(dp[node] != -1) return dp[node];

        //     int maxv = INT_MIN;
        //     for(int i = node + 1;i < n;i++){
        //         int dif = nums[i] - nums[node];

        //         if(-target <= dif && dif <= target){
        //             int res = solve(i);
        //             if(res != INT_MIN){
        //                 maxv = max(maxv,1 + res);
        //             }
        //         }
        //     }

        //     return dp[node] = maxv;
        // };

        // memset(dp,-1,sizeof(dp));
        // int res = solve(0);

        // return (res == INT_MIN ? -1 : res);


        //************ dynamic programming (Tabulation)*************

        vector<int> dp(n,INT_MIN);
        dp[n - 1] = 0;
        for(int i = n - 2;i >= 0;i--){
            int maxv = INT_MIN;
            for(int j = i + 1;j < n;j++){
                int diff = nums[j] - nums[i];

                if(-target <= diff && diff <= target && dp[j] != INT_MIN){
                    maxv = max(maxv,1 + dp[j]);
                }
            }
            dp[i] = maxv;
        }

        return (dp[0] == INT_MIN ? -1 : dp[0]);
    }
};