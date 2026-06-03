class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int, int>> land(n), water(m);

        for (int i = 0; i < n; i++) {
            land[i] = {landStartTime[i], landDuration[i]};
        }

        for (int i = 0; i < m; i++) {
            water[i] = {waterStartTime[i], waterDuration[i]};
        }

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        vector<int> landSuf(n), waterSuf(m);

        int mn = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, land[i].first + land[i].second);
            landSuf[i] = mn;
        }

        mn = INT_MAX;

        for (int i = m - 1; i >= 0; i--) {
            mn = min(mn, water[i].first + water[i].second);
            waterSuf[i] = mn;
        }

        vector<int> landPref(n), waterPref(m);

        mn = INT_MAX;

        for (int i = 0; i < n; i++) {
            mn = min(mn, land[i].second);
            landPref[i] = mn;
        }

        mn = INT_MAX;

        for (int i = 0; i < m; i++) {
            mn = min(mn, water[i].second);
            waterPref[i] = mn;
        }

        int ans = INT_MAX;

        auto lbWater = [&](int target) {
            return lower_bound(water.begin(), water.end(),
                               pair<int, int>{target, -1}) -
                   water.begin();
        };

        auto lbLand = [&](int target) {
            return lower_bound(land.begin(), land.end(),
                               pair<int, int>{target, -1}) -
                   land.begin();
        };

        for (int i = 0; i < n; i++) {

            int end = land[i].first + land[i].second;

            int idx = lbWater(end);

            if (idx < m) {
                ans = min(ans, waterSuf[idx]);
            }

            if (idx > 0) {
                ans = min(ans, end + waterPref[idx - 1]);
            }
        }

        for (int i = 0; i < m; i++) {

            int end = water[i].first + water[i].second;

            int idx = lbLand(end);

            if (idx < n) {
                ans = min(ans, landSuf[idx]);
            }

            if (idx > 0) {
                ans = min(ans, end + landPref[idx - 1]);
            }
        }

        return ans;
    }
};