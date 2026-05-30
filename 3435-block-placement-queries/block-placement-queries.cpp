class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int maxl = 50000;

        set<int> set = {0,maxl};
        vector<int> tree(maxl * 4,0);
        
        function<void(int,int,int,int,int)> update = [&](int node,int l,int r,int idx,int val)->void{
        
            if(idx < l || r < idx) return;

            if(l == r){
                tree[node] = val;
                return;
            }
            int mid = (l + r)/2;

            update(node * 2 + 1,l,mid,idx,val);
            update(node * 2 + 2,mid + 1,r,idx,val);

            tree[node] = max(tree[node * 2 + 1],tree[node * 2 + 2]);
        };

        function<int(int,int,int,int,int)> query = [&](int node,int ql,int qr,int l,int r)->int{
            if(r < ql || qr < l) return 0;
            if(ql <= l && r <= qr) return tree[node];

            int mid = (l + r)/2;

            return max(query(node * 2 + 1,ql,qr,l,mid),query(node * 2 + 2,ql,qr,mid + 1,   r));
        };  

        vector<bool> result;

        for(auto& qry : queries){
            int t = qry[0];

            if(t == 1){
                int x = qry[1];
                auto it = set.upper_bound(x);

                int nxt = *it;
                int prv = *prev(it);

                update(0,0,maxl,x,x - prv);
                update(0,0,maxl,nxt,nxt - x);

                set.insert(x);
            }
            else{
                int x = qry[1];
                int sz = qry[2];
                
                auto it = set.upper_bound(x);
                --it;

                int prv = *it;

                int max_sz = query(0,0,prv,0,maxl);
                max_sz = max(max_sz,x - prv);

                result.push_back(max_sz >= sz);
            }
        } 

        return result;
    }
};