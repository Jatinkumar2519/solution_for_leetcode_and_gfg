class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int K) {
        int n = stations.size();
        class SegmentTree {
            vector<long long> tree;

        public:
            SegmentTree(int n) { tree.assign(4 * n, 0); }
            void update(int node, int l, int r, int indx, long long val) {
                if (indx < l || indx > r)
                    return;
                if (l == r) {
                    tree[node] += val;
                    return;
                }
                int mid = (l + r) / 2;
                update(node * 2 + 1, l, mid, indx, val);
                update(node * 2 + 2, mid + 1, r, indx, val);
                tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
            }

            long long query(int node, int l, int r, int ql, int qr) {
                if (r < ql || l > qr)
                    return 0;
                if (ql <= l && r <= qr)
                    return tree[node];
                int mid = (l + r) / 2;
                return query(node * 2 + 1, l, mid, ql, qr) +
                       query(node * 2 + 2, mid + 1, r, ql, qr);
            }
        };
        vector<long long> prefix(n, 0);
        prefix[0] = stations[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stations[i];
        }
        auto feasible = [&](long long mid, long long k) {
            SegmentTree SegT = SegmentTree(n);
            for (int i = 0; i < n; i++) {
                int left = max(i - r, 0);
                int right = min(i + r, n - 1);
                long long sum =
                    (left == 0) ? prefix[right]: prefix[right] - prefix[left - 1];
                sum += SegT.query(0, 0, n - 1,left, right);
                if (sum < mid) {
                    long long diff = mid - sum;
                    if (diff > k)
                        return false;
                    int indx = min(i + r, n - 1);
                    SegT.update(0, 0, n - 1, indx, diff);
                    k -= diff;
                }
            }
            return true;
        };
        long long left = INT_MAX;
        long long right = INT_MIN;
        for (int i = 0; i < n; i++) {
            int lft = max(i - r, 0);
            int rght = min(i + r, n - 1);
            long long sum =
                (lft == 0) ? prefix[rght] : prefix[rght] - prefix[lft - 1];
            left = min(left, sum);
            right = max(right, sum);
        }
        right += K;
        long long res = -1;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (feasible(mid, K)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};