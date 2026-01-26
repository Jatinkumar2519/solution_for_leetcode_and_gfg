class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> graph(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        auto solve = [&](int node,vector<int>& arr){
            queue<tuple<int,int,int>> q;
            q.push(make_tuple(node,-1,0));
            
            while(!q.empty()){
                auto [temp,par,dist] = q.front();q.pop();

                arr[temp] = dist;
                for(int nn : graph[temp]){
                    if(nn == par) continue;
                    q.push(make_tuple(nn,temp,dist + 1));
                }
            }
        };

        vector<int> arr1(n,0),arr2(n,0),arr3(n,0);

        solve(x,arr1);
        solve(y,arr2);
        solve(z,arr3);

        int count = 0;

        for(int i = 0;i < n;i++){
            int num1 = min({arr1[i],arr2[i],arr3[i]});
            int num3 = max({arr1[i],arr2[i],arr3[i]});
            int num2 = arr1[i] + arr2[i] + arr3[i] - num1 - num3;

            if((num1 * 1LL *  num1) + (num2 * 1LL *  num2) == (num3 * 1LL *  num3))
                count++;
        }

        return count;
    }
};