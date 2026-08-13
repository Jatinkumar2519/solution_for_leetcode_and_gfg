class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();

        struct Node {
            char left, right;
            int pre, suf, mx, len;

            Node(char ch = '_') {
                left = right = ch;
                pre = suf = mx = 1;
                len = 1;
            }
        };

        vector<Node> tree(4 * n);

        auto merge = [&](Node &a, Node &b) {
            Node res;

            res.len = a.len + b.len;

            res.left = a.left;
            res.right = b.right;

            // Prefix
            res.pre = a.pre;

            if (a.pre == a.len && a.right == b.left) {
                res.pre = a.len + b.pre;
            }

            // Suffix
            res.suf = b.suf;

            if (b.suf == b.len && a.right == b.left) {
                res.suf = b.len + a.suf;
            }

            // Maximum
            res.mx = max(a.mx, b.mx);

            if (a.right == b.left) {
                res.mx = max(res.mx, a.suf + b.pre);
            }

            return res;
        };

        function<void(int, int, int)> build =
            [&](int node, int l, int r) {

                if (l == r) {
                    tree[node] = Node(s[l]);
                    return;
                }

                int mid = (l + r) / 2;

                build(node * 2 + 1, l, mid);
                build(node * 2 + 2, mid + 1, r);

                tree[node] =
                    merge(tree[node * 2 + 1],
                          tree[node * 2 + 2]);
            };

        function<void(int, int, int, int, char)> update =
            [&](int node, int l, int r, int idx, char ch) {

                if (l == r) {
                    tree[node] = Node(ch);
                    return;
                }

                int mid = (l + r) / 2;

                if (idx <= mid) {
                    update(node * 2 + 1, l, mid, idx, ch);
                } else {
                    update(node * 2 + 2, mid + 1, r, idx, ch);
                }

                tree[node] =
                    merge(tree[node * 2 + 1],
                          tree[node * 2 + 2]);
            };

        build(0, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(0, 0, n - 1,
                   queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(tree[0].mx);
        }

        return ans;
    }
};