class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];
        
        for(int i = 1;i < n;i++){
            prefix[i] = prefix[i - 1] ^ nums[i];
        }

        vector<int> tree(4 * n);
        
        function<void(int,int,int,int,int)> update = [&](int node,int l,int r,int idx,int val)->void{
            if(idx < l || r < idx) return;
            if(l == r){
                tree[node] = val;
                return;
            }

            int mid = (l + r)/2;
            update(node * 2 + 1,l,mid,idx,val);
            update(node * 2 + 2,mid + 1,r,idx,val);

            tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
        };

        function<int(int,int,int,int,int)> query = [&](int node,int l,int r,int ql,int qr)->int{
            if(r < ql || qr < l) return 0;
            if(ql <= l && r <= qr) return tree[node];

            int mid = (l + r)/2;

            return query(node * 2 + 1,l,mid,ql,qr) + 
                query(node * 2 + 2,mid + 1,r,ql,qr);
        };

        int m = queries.size();
        vector<bool> result(m);
        unordered_map<int,int> last;
        unordered_map<int, vector<pair<int,int>>> preQueries;

        for(int i = 0;i < m;i++){
            vector<int> q = queries[i];
            int l = q[0];
            int r = q[1];

            preQueries[r].push_back({l,i});
        }

        for(int i = 0;i < n;i++){
            if(last.find(nums[i]) != last.end()){
                update(0,0,n - 1,last[nums[i]],0);
            }
            update(0,0,n - 1,i,1);
            last[nums[i]] = i;
            
            for(auto& [l,idx] : preQueries[i]){
                int x = (l == 0) ? prefix[i] : prefix[i] ^ prefix[l - 1];
                int count = query(0,0,n - 1,l,i);

                if((i - l + 1) % 2 == 0 && count == k && x == 0){
                    result[idx] = true;
                }
            }
        }

        return result;
    }
};