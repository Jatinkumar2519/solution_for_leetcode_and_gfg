
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        int n = arrival.size();
        vector<int> count(k, 0);

        set<int> set1;
        set<pair<long long, int>> set2;

        for (int i = 0; i < k; i++) {
            set1.insert(i);
        }

        for (int i = 0; i < n; i++) {

            long long ts = arrival[i];

            while (!set2.empty() &&
                   set2.begin()->first <= ts) {

                int id = set2.begin()->second;

                set1.insert(id);
                set2.erase(set2.begin());
            }

            if (set1.empty()) continue;

            int req = i % k;
            auto it = set1.lower_bound(req);

            if (it == set1.end()) {
                it = set1.begin();
            }

            int id = *it;
            set1.erase(it);

            set2.insert({ts + load[i], id});

            count[id]++;
        }

        vector<int> result;

        int mx = *max_element(count.begin(), count.end());

        for (int i = 0; i < k; i++) {
            if (count[i] == mx) {
                result.push_back(i);
            }
        }

        return result;
    }
};
