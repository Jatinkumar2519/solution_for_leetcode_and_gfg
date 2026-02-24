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
    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        function<void(TreeNode*,int)> solve = [&](TreeNode* node,int num){
            if(!node) return;
            if(!node->left && !node->right){
                total += ((num << 1) | node->val);
                return;
            }
            solve(node->left,(num << 1) | node->val);
            solve(node->right,(num << 1) | node->val);
        };

        solve(root,0);
        return total;
    }
};