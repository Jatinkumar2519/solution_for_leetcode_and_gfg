class Solution {
public:
    struct SegmentTree{
        vector<pair<int,int>> tree;
        SegmentTree(int n,vector<pair<int,int>>& arr){
            tree.resize(4 * n);
            BuildTree(arr,0,0,n - 1);
        }
        void BuildTree(vector<pair<int,int>>& arr,int node,int l,int r){
            if(l == r){
                tree[node] = arr[l];
                return;
            }
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            BuildTree(arr,left,l,mid);
            BuildTree(arr,right,mid + 1,r);
            if(tree[left].second > tree[right].second){
                tree[node] = tree[right];
            }
            else{
                tree[node] = tree[left];
            }
        }
        void update(int node,int indx,int l,int r){
            if(indx < l || r < indx) return;
            if(l == r){
                tree[node].second = INT_MAX;
                return;
            }
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            if(indx <= mid)
                update(left,indx,l,mid);
            else
                update(right,indx,mid + 1,r);
            if(tree[left].second > tree[right].second){
                tree[node] = tree[right];
            }
            else{
                tree[node] = tree[left];
            }
        }
        pair<int,int> query(int node,int ql,int qr,int l,int r){
            if(qr < l || r < ql) return {INT_MAX,INT_MAX};
            if(ql <= l && r <= qr) return tree[node];
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            auto _left = query(left,ql,qr,l,mid);
            auto _right = query(right,ql,qr,mid + 1,r);
            if(_left.second > _right.second){
                return _right;
            }
            else{
                return _left;
            }
        }
    };
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        map<pair<int,int>,int> map;
        vector<pair<int,int>> arr(n);
        for(int i = 0;i < n;i++){
            arr[i] = {baskets[i],i};
        }
        sort(arr.begin(),arr.end());
        for(int i = 0;i < n;i++){
            map[arr[i]] = i;
        }
        SegmentTree segt(n,arr);
        int count = 0;
        for(int i = 0;i < n;i++){
            int left = 0;
            int right = n - 1;
            while(left < right){
                int mid = (left + right) >> 1;
                if(arr[mid].first < fruits[i]){
                    left = mid + 1;
                }
                else{
                    right = mid;
                }
            }
            pair<int,int> pair = segt.query(0,left,n - 1,0,n - 1);
            if(pair.first >= fruits[i] && pair.second != INT_MAX){
                count++;
                segt.update(0,map[{pair}],0,n - 1);
            }
        }
        return n - count;
    }
};