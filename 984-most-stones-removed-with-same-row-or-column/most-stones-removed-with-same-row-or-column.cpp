class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int> parent,rank;
        function<int(int)> find = [&](int num)->int{
            if(parent.find(num) == parent.end()) return num;
            return parent[num] = find(parent[num]);
        };
        function<void(int,int)> Union = [&](int num1,int num2)->void{
            int p1 = find(num1);
            int p2 = find(num2);
            if(p1 == p2) return;
            if(rank[p1] > rank[p2]){
                parent[p2] = p1;
            }
            else if(rank[p1] < rank[p2]){
                parent[p1] = p2;
            }
            else{
                rank[p1]++;
                parent[p2] = p1;
            }
        };
        for(auto& stone : stones){
            Union(stone[0],stone[1] + 10001);
        }
        unordered_set<int> groups;
        for(auto& stone : stones){
            groups.insert(find(stone[0]));
        }
        return stones.size() - groups.size();
    }
};