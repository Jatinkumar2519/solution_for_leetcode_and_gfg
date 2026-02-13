/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        function<TreeNode*(TreeNode*)> solve = [&](TreeNode* node)->TreeNode*{
            if(!node) return nullptr;

            if(node == p || node == q) return node;

            auto left = solve(node->left);
            auto right = solve(node->right);

            if(left && right){
                return node;
            }
            else if(left && !right){
                return left;
            }
            return right;
        };

        return solve(root);
    }
};