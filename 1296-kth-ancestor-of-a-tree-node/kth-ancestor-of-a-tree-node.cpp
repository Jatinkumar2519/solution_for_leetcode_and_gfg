class TreeAncestor {
public:
    int maxv;
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        maxv = log2(n) + 1;
        dp = vector<vector<int>>(n,vector<int>(maxv,-1));
        for(int i = 0;i < n;i++){
            dp[i][0] = parent[i];
        }
        for(int j = 1;j < maxv;j++){
            for(int i = 0;i < n;i++){
                if(dp[i][j - 1] != -1){
                    dp[i][j] = dp[dp[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = maxv - 1;i >= 0;i--){
            if(k & (1 << i)){
                if(dp[node][i] == -1) return -1;
                node = dp[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */