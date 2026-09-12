class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) {
                 return a[0] < b[0];
             });

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5, {-1, {}})
        );

        auto getNext = [&](int end) -> int {
            int left = 0;
            int right = n;

            while (left < right) {
                int mid = (left + right) / 2;

                if (intervals[mid][0] <= end)
                    left = mid + 1;
                else
                    right = mid;
            }

            return left;
        };

        function<pair<long long, vector<int>>(int, int)> solve =
            [&](int idx, int k) -> pair<long long, vector<int>> {

            if (idx == n || k == 4)
                return {0, {}};

            if (dp[idx][k].first != -1)
                return dp[idx][k];

            // Don't take current interval
            auto skip = solve(idx + 1, k);

            // Take current interval
            int next = getNext(intervals[idx][1]);

            auto take = solve(next, k + 1);

            take.first += intervals[idx][2];
            take.second.push_back(intervals[idx][3]);

            sort(take.second.begin(),take.second.end());
            sort(skip.second.begin(),skip.second.end());
            
            if (take.first > skip.first) {
                dp[idx][k] = take;
            }
            else if (take.first < skip.first) {
                dp[idx][k] = skip;
            }
            else {
                dp[idx][k] = min(take, skip);
            }

            return dp[idx][k];
        };

        auto ans = solve(0, 0);
        return ans.second;
    }
};