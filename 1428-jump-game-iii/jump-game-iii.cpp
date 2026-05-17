class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<int> visit(n,false);
        visit[start] = true;

        queue<int> q{{start}};
        while(!q.empty()){
            int len = q.size();

            while(len--){
                int node = q.front();q.pop();
                if(arr[node] == 0) return true;

                if(node + arr[node] < n && !visit[node + arr[node]]){
                    visit[node + arr[node]] = true;
                    q.push(node + arr[node]);
                }

                if(node - arr[node] >= 0 && !visit[node - arr[node]]){
                    visit[node - arr[node]] = true;
                    q.push(node - arr[node]);
                }
            }
        }

        return false;
    }
};