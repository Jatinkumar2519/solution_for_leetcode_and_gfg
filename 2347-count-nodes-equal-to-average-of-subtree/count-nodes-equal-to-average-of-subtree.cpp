/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {

        int count = 0;
        function<pair<int,int>(TreeNode*)> solve = [&](TreeNode* node)->pair<int,int>{
            if(!node) return {0,0};

            auto left = solve(node->left);
            auto right = solve(node->right);

            pair<int,int> mid = {left.first + right.first + node->val,
                                 left.second + right.second + 1};
            
            count += (mid.first/mid.second == node->val);

            return mid;
        };

        solve(root);
        return count;
    }
};