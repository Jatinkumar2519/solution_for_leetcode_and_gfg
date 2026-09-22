class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {

        int n = nums.size();

        struct Node {
            int prod = 1;
            int cnt[6] = {};
        };

        vector<Node> tree(4 * n, Node());

        auto merge = [&](const Node& a, const Node& b) {
            Node c;

            for (int r = 0; r < k; r++) {
                c.cnt[r] += a.cnt[r];
            }

            for (int r = 0; r < k; r++) {

                int newRem = (a.prod * r) % k;

                c.cnt[newRem] += b.cnt[r];
            }

            c.prod = (a.prod * b.prod) % k;

            return c;
        };


        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {

                int rem = nums[l] % k;

                tree[node].cnt[rem] = 1;
                tree[node].prod = rem;

                return;
            }

            int mid = (l + r) / 2;

            build(node * 2 + 1, l, mid);
            build(node * 2 + 2, mid + 1, r);

            tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
        };

        build(0, 0, n - 1);


        function<void(int, int, int, int, int)> update =
            [&](int node, int l, int r, int idx, int val) {
                if (l == r) {

                    int rem = nums[idx] % k;
                    tree[node].cnt[rem] = 0;

                    rem = val % k;
                    tree[node].cnt[rem] = 1;
                    tree[node].prod = rem;

                    return;
                }

                int mid = (l + r) / 2;

                if (idx <= mid) {

                    update(node * 2 + 1, l, mid, idx, val);

                } else {

                    update(node * 2 + 2, mid + 1, r, idx, val);
                }

                tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
            };


        function<Node(int, int, int, int, int)> query =
            [&](int node, int ql, int qr, int l, int r) -> Node {

            if (qr < l || r < ql) {
                return Node();
            }

            if (ql <= l && r <= qr) {
                return tree[node];
            }

            int mid = (l + r) / 2;

            Node left = query(node * 2 + 1, ql, qr, l, mid);

            Node right = query(node * 2 + 2, ql, qr, mid + 1, r);

            return merge(left, right);
        };

        vector<int> result;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(0, 0, n - 1, index, value);
            nums[index] = value;

            Node ans = query(0, start, n - 1, 0, n - 1);

            result.push_back(ans.cnt[x]);
        }

        return result;
    }
};