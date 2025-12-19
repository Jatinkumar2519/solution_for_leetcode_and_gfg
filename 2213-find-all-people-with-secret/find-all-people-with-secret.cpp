class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> knows(n, false);
        knows[0] = knows[firstPerson] = true;

        map<int, vector<pair<int,int>>> meetingGroups;
        for (auto &m : meetings)
            meetingGroups[m[2]].push_back({m[0], m[1]});

        for (auto &[_, group] : meetingGroups) {

            unordered_map<int,int> parent, rank;

            function<int(int)> find = [&](int x) {
                if (parent[x] == x) return x;
                return parent[x] = find(parent[x]);
            };

            auto Union = [&](int a, int b) {
                a = find(a); b = find(b);
                if (a == b) return;
                if (rank[a] < rank[b]) swap(a, b);
                parent[b] = a;
                if (rank[a] == rank[b]) rank[a]++;
            };
            
            for (auto &[u,v] : group) {
                if (!parent.count(u)) parent[u] = u, rank[u] = 0;
                if (!parent.count(v)) parent[v] = v, rank[v] = 0;
                Union(u, v);
            }

            unordered_map<int, vector<int>> components;
            for (auto &[u,v] : group) {
                components[find(u)].push_back(u);
                components[find(v)].push_back(v);
            }

            for (auto &[_, nodes] : components) {
                bool hasSecret = false;
                for (int x : nodes)
                    if (knows[x]) hasSecret = true;

                if (hasSecret) {
                    for (int x : nodes)
                        knows[x] = true;
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++)
            if (knows[i]) result.push_back(i);

        return result;
    }
};
