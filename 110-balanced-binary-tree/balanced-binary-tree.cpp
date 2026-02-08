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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> solve = [&](TreeNode* node)->int{
            if(!node) return 0;
            
            int left = solve(node->left);
            int right = solve(node->right);

            if(left == -1 || right == -1 || (abs(left - right) > 1)) return -1;
            return 1 + max(left,right);
        };

        if(solve(root) == -1) return false;
        return true;
    }
};