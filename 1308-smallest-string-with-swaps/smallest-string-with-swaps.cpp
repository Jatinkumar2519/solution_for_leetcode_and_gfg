class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int> parent(n),rank(n,0);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
        function<int(int)> find = [&](int num) -> int{
            if(parent[num] == num) return num;
            return parent[num] = find(parent[num]);
        };
        function<void(int,int)> Union = [&](int n1,int n2) -> void{
            int p1 = find(n1);
            int p2 = find(n2);
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
        for(auto& pair : pairs){
            Union(pair[0],pair[1]);
        }
        unordered_map<int,vector<int>> map;
        for(int i = 0;i < n;i++){
            map[find(i)].push_back(i);
        }
        for(auto& [_,arr] : map){
            vector<char> chars;
            for(int i = 0;i < arr.size();i++){
                chars.push_back(s[arr[i]]);
            }
            sort(chars.begin(),chars.end());
            for(int i = 0;i < arr.size();i++){
                s[arr[i]] = chars[i];
            }
        }
        return s;
    }
};