class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> parent(n),rank(n,0);
        for(int i = 0;i < n;i++) parent[i] = i;

        function<int(int)> find = [&](int node)->int{
            if(parent[node] == node) return node;
            return parent[node] = find(parent[node]);
        };

        auto Union = [&](int node1,int node2){
            int par1 = find(node1);
            int par2 = find(node2);

            if(par1 == par2) return;
            if(rank[par1] > rank[par2]){
                parent[par2] = par1;
            }
            else if(rank[par1] < rank[par2]){
                parent[par1] = par2;
            }
            else{
                parent[par1] = par2;
                rank[par2]++;
            }
        };

        vector<pair<int,int>> arr(n);
        for(int i = 0;i < n;i++){
            arr[i] = make_pair(nums[i],i);
        }

        sort(arr.begin(),arr.end());
        stack<pair<int,int>> s;

        for(auto [num,idx] : arr){
            while(!s.empty() && (num - s.top().first) <= limit){
                Union(idx,s.top().second);
                s.pop();
            }
            s.push({num,idx});
        }

        unordered_map<int,vector<int>> comp;
        for(int node = 0;node < n;node++){

            int par = find(node);
            comp[par].push_back(node);
        }

        for(auto& [_,indices] : comp){
            
            int m = indices.size();
            sort(indices.begin(),indices.end());
            
            vector<int> temp(m);
            for(int i = 0;i < m;i++){
                temp[i] = nums[indices[i]];
            }

            sort(temp.begin(),temp.end());

            for(int i = 0;i < m;i++){
                nums[indices[i]] = temp[i];
            }
        }

        return nums;
    }
};