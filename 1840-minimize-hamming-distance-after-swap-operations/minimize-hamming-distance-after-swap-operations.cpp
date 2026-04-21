class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        vector<int> parent(n),rank(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }

        function<int(int)> find = [&](int node)->int{
            if(node == parent[node]) return node;
            return parent[node] = find(parent[node]);
        };

        auto Union = [&](int node1,int node2)-> void{
            int p1 = find(node1);
            int p2 = find(node2);

            if(p1 == p2) return;
            if(rank[p1] > rank[p2]) parent[p2] = p1;
            else if(rank[p1] < rank[p2]) parent[p1] = p2;
            else{
                rank[p1]++;
                parent[p2] = p1;
            }
        };

        for(auto& pr : allowedSwaps){
            Union(pr[0],pr[1]);
        }

        unordered_map<int,vector<int>> map;
        for(int i = 0;i < n;i++){
            int par = find(i);
            map[par].push_back(i);
        }

        int count = 0;
        for(auto& [_,arr] : map){
            vector<int> nums1,nums2;

            for(int idx : arr){
                nums1.push_back(source[idx]);
                nums2.push_back(target[idx]);
            }

            multiset<int> set(nums1.begin(),nums1.end());
            for(int num : nums2){
                if(set.find(num) != set.end()){
                    set.erase(set.find(num));
                }
            }

            count += set.size();
        }

        return count;
    }
};