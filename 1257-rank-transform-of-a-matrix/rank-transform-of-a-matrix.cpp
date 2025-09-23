class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0), col(m, 0);
        vector<vector<int>> result(n, vector<int>(m, 0));
        map<int, vector<pair<int, int>>> value_to_pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                value_to_pos[matrix[i][j]].push_back({i, j});
            }
        }
        for (auto& it : value_to_pos) {
            vector<pair<int, int>> positions = it.second;
            unordered_map<int, int> rankk;
            unordered_map<int, int> parent;
            function<int(int)> find = [&](int num) -> int {
                if (parent.find(num) == parent.end())
                    return num;
                return parent[num] = find(parent[num]);
            };
            function<void(int, int)> Union = [&](int num1, int num2) -> void {
                int p1 = find(num1);
                int p2 = find(num2);
                if (p1 == p2)
                    return;
                if (rankk[p1] > rankk[p2]) {
                    parent[p2] = p1;
                } else if (rankk[p1] < rankk[p2]) {
                    parent[p1] = p2;
                } else {
                    rankk[p1]++;
                    parent[p2] = p1;
                }
            };
            for (auto& pos : positions) {
                int x = pos.first;
                int y = pos.second;
                Union(x, n + y);
            }
            unordered_map<int, vector<pair<int, int>>> groups;
            for (auto& pos : positions) {
                int x = pos.first;
                int y = pos.second;
                groups[find(x)].push_back({x, y});
            }
            for (auto& [_, group] : groups) {
                int maxrank = 0;
                for (auto& [x, y] : group) {
                    maxrank = max({maxrank, row[x], col[y]});
                }
                int newrank = maxrank + 1;
                for (auto& [x, y] : group) {
                    result[x][y] = newrank;
                    row[x] = max(row[x], newrank);
                    col[y] = max(col[y], newrank);
                }
            }
        }
        return result;
    }
};