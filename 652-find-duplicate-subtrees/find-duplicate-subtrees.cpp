/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        unordered_map<string, int> count;
        unordered_map<string, TreeNode*> visited;

        function<string(TreeNode*)> solve = [&](TreeNode* node) -> string {
            if (!node)
                return "N";

            string left = solve(node->left);
            string right = solve(node->right);

            string key =
                "{" + left + "}" + to_string(node->val) + "{" + right + "}";

            count[key]++;
            visited[key] = node;

            return key;
        };

        solve(root);

        // vector<pair<string, int>> temp;
        // for (auto& [key, freq] : count) {
        //     temp.push_back({key, freq});
        // }

        // sort(temp.begin(), temp.end(), [&](auto& a, auto& b) {
        //     return a.first.length() < b.first.length();
        // });

        vector<TreeNode*> result;
        for (auto& [key, freq] : count) {
            if (freq > 1) {
                result.push_back(visited[key]);
            }
        }

        return result;
    }
};