class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& bulbs,vector<vector<int>>& queries) {

        unordered_map<int, int> dia, antiDia, row, col;

        set<pair<int, int>> hasBulb;

        for (auto& bulb : bulbs) {

            int x = bulb[0];
            int y = bulb[1];

            if (hasBulb.count(make_pair(x, y)))
                continue;

            row[x]++;
            col[y]++;
            dia[x - y]++;
            antiDia[x + y]++;

            hasBulb.insert(make_pair(x, y));
        }

        int dirx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        vector<int> result;
        for (auto& query : queries) {
            int x = query[0];
            int y = query[1];

            result.push_back((row[x] > 0 || col[y] > 0 || dia[x - y] > 0 ||
                              antiDia[x + y] > 0));

            if (hasBulb.count(make_pair(x, y))) {
                row[x]--;
                col[y]--;
                dia[x - y]--;
                antiDia[x + y]--;

                hasBulb.erase(make_pair(x, y));
            }

            for (int d = 0; d < 8; d++) {
                int nx = x + dirx[d];
                int ny = y + diry[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    hasBulb.count(make_pair(nx, ny))) {

                    row[nx]--;
                    col[ny]--;
                    dia[nx - ny]--;
                    antiDia[nx + ny]--;

                    hasBulb.erase(make_pair(nx, ny));
                }
            }
        }

        return result;
    }
};