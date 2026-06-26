class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        using ll = long long;
        class SegmentTree{
        public:
            vector<int> tree;
            SegmentTree(int n){
                tree = vector<int>(4 * n,0);
            }
            void update(int node,int l,int r,int indx){
                if(indx < l || r < indx) return;
                if(l == r){
                    tree[node] += 1;
                    return;
                }
                int mid = (l + r)/2;
                update(node * 2 + 1,l,mid,indx);
                update(node * 2 + 2,mid + 1,r,indx);
                tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
            }
            int query(int node,int ql,int qr,int l,int r){
                if(qr < l || r < ql) return 0;
                if(ql <= l && r <= qr) return tree[node];
                int mid = (l + r)/2;
                return query(node * 2 + 1,ql,qr,l,mid) + query(node * 2 + 2,ql,qr,mid + 1,r);
            }
        };
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(nums[i] == target){
                nums[i] = 1;
            }
            else{
                nums[i] = -1;
            }
        }
        vector<ll> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        set<ll> set(prefix.begin(),prefix.end());
        vector<ll> sorted(set.begin(),set.end());
        unordered_map<ll,int> rank;
        n = sorted.size();
        for(int i = 0;i < n;i++){
            rank[sorted[i]] = i;
        }
        SegmentTree seg = SegmentTree(n);
        ll count = 0;
        for(int i = 0;i < prefix.size();i++){
            int indx = rank[prefix[i]];
            if(indx > 0){
                count += seg.query(0,0,indx - 1,0,n - 1);
            }
            seg.update(0,0,n - 1,indx);
        }
        return count;
    }
};