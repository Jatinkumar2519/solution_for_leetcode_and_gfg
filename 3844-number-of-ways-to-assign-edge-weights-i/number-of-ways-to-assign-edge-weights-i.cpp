class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int mod = 1e9 + 7;
        int maxv = 1e5 + 1;
        int n = edges.size() + 1;
        vector<vector<int>> tree(n);

        for(auto& edge : edges){
            edge[0]--;edge[1]--;

            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        int maxd = 0;
        function<void(int,int,int)> dfs = [&](int node,int par,int d){
            maxd = max(maxd,d);

            for(int nn : tree[node]){
                if(par == nn) continue;

                dfs(nn,node,d + 1);
            }
        };
        dfs(0,-1,0);

        auto power = [&](int a,int x)->int{
            int res = 1;

            while(x > 0){
                if(x & 1){
                    res = (res * 1LL * a) % mod;
                }

                a = (a * 1LL * a) % mod;
                x >>= 1;
            }

            return res;
        };

        int fact[100001];
        int invFact[100001];

        fact[0] = 1;
        for(int i = 1;i < maxv;i++){
            fact[i] = (fact[i - 1] * 1LL * i) % mod;
        }

        invFact[maxv - 1] = power(fact[maxv - 1],mod - 2);
        for(int i = maxv - 2;i >= 0;i--){
            invFact[i] = (invFact[i + 1] * 1LL * (i + 1)) % mod;
        }

        auto aCr = [&](int a,int r)->int{
            return (((fact[a] * 1LL * invFact[a - r]) % mod) * 1LL * invFact[r]) % mod;
        };

        int count = 0;
        for(int one = 1;one <= maxd;one += 2){
            count = (count + aCr(maxd,one)) % mod;
        }

        return count;
    }
};