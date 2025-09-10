class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> check;
        for (auto& arr : obstacles) {
            check.insert({arr[0], arr[1]});
        }
        int x = 0, y = 0;
        int dir = 0, maxd = 0;
        int dirx[] = {0, 1, 0, -1};
        int diry[] = {1, 0, -1, 0};
        for (int& c : commands) {
            if (c == -1) {
                dir = (dir + 1) % 4;
            } else if (c == -2) {
                dir = (dir - 1 + 4) % 4;
            } else {
                for (int i = 0; i < c; i++) {
                    if (check.count({x + dirx[dir], y + diry[dir]}) == 0) {
                        x += dirx[dir];
                        y += diry[dir];
                        maxd = max(maxd, x * x + y * y);
                    } else {
                        break;
                    }
                }
            }
        }
        return maxd;
    }
};