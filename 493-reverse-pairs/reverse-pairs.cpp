class Solution {
  public:
    vector<int> tree;
    void update(int node,int indx,int l,int r){
        if(indx < l || r < indx) return;
        if(l == r){
            tree[node] += 1;
            return;
        }
        int mid = (l + r) >> 1;
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        if(indx <= mid){
            update(left,indx,l,mid);
        }
        else{
            update(right,indx,mid + 1,r);
        }
        tree[node] = tree[left] + tree[right];
    }
    int query(int node,int ql,int qr,int l,int r){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r) >> 1;
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        return query(left,ql,qr,l,mid) + query(right,ql,qr,mid + 1,r);
    }
    int reversePairs(vector<int> &arr) {
        int n = arr.size();
        vector<long long> vals;
        vals.reserve(n * 2);
        for(int i = 0;i < n;i++){
            vals.push_back(arr[i]);
            vals.push_back(2LL * arr[i]);
        }
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        unordered_map<long long,int> map;
        int len = vals.size();
        for(int i = 0;i < len;i++){
            map[vals[i]] = i;
        }
        int count = 0;
        tree.resize(4 * len);
        for(int i = n - 1;i >= 0;i--){
            if(map[arr[i]] - 1 >= 0)
                count += query(0,0,map[arr[i]] - 1,0,len - 1);
            update(0,map[2LL * arr[i]],0,len - 1);
        }
        return count;
    }
};