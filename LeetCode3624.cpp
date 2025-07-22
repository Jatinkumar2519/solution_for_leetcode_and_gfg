# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    using ll = long long;
    // segment tree 
    struct SegmentTree{
        vector<vector<ll>> tree;
        SegmentTree(int n,vector<ll> arr){
            tree.resize(4 * n,vector<ll>(10,0));
            BuildTree(arr,0,0,n - 1);
        }
        ll pop_count(ll num){
            int count = 0;
            while(num != 1){
                count++;
                num = __builtin_popcount(num);
            }
            return count;
        }
        void BuildTree(vector<ll>& arr,int node,int l,int r){
            if(l == r){
                tree[node][pop_count(arr[l])]++;
                return;
            }
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            BuildTree(arr,left,l,mid);
            BuildTree(arr,right,mid + 1,r);
            for(int i = 0;i < 10;i++){
                tree[node][i] = tree[left][i] + tree[right][i];
            }
        }
        void update(int node,ll val,int indx,ll prev,int l,int r){
            if(indx < l || r < indx) return;
            if(l == r){
                int pc_p = pop_count(prev);
                int pc = pop_count(val);
                tree[node][pc_p]--;
                tree[node][pc]++;
                return;
            }
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            if(indx <= mid){
                update(left,val,indx,prev,l,mid);
            }
            else{
                update(right,val,indx,prev,mid + 1,r);
            }
            for(int i = 0;i < 10;i++){
                tree[node][i] = tree[left][i] + tree[right][i];
            }
        }
        int query(int node,int ql,int qr,int l,int r,int k){
            if(qr < l || r < ql) return 0;
            if(ql <= l && r <= qr) return tree[node][k];
            int mid = (l + r) >> 1;
            int left = (node << 1) + 1;
            int right = (node << 1) + 2;
            return query(left,ql,qr,l,mid,k) + query(right,ql,qr,mid + 1,r,k);
        }
    };
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        SegmentTree code(n,nums);
        vector<int> result;
        for(auto& query : queries){
            if(query[0] == 1){
                result.push_back(code.query(0,query[1],query[2],0,n - 1,query[3]));
            }
            else{
                code.update(0,query[2],query[1],nums[query[1]],0,n - 1);
                nums[query[1]] = query[2];
            }
        }
        return result;
    }
};
