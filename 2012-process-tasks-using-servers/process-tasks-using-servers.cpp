class Compare {
public:
    bool operator()(auto& a, auto& b) {

        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    };
};
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = tasks.size();
        int n = servers.size();

        vector<int> result(m);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> avbl,
            unavbl;

        // avbl - {weight, server_id}
        // unavbl - {time to free, server_id};

        for (int i = 0; i < n; i++)
            avbl.push({servers[i], i});

        long long ts = 0;
        for (int i = 0; i < m; i++) {
            ts = max(ts, (long long)i);

            while (!unavbl.empty() && unavbl.top().first <= ts) {

                auto [_, id] = unavbl.top();
                avbl.push({servers[id], id});
                unavbl.pop();
            }

            if (avbl.empty()) {

                auto [t, id] = unavbl.top();
                ts = t;

                while (!unavbl.empty() && unavbl.top().first <= ts) {

                    auto [_, id] = unavbl.top();
                    avbl.push({servers[id], id});
                    unavbl.pop();
                }
            }

            auto [_, id] = avbl.top();
            avbl.pop();

            unavbl.push({ts + tasks[i], id});
            result[i] = id;
        }

        return result;
    }
};