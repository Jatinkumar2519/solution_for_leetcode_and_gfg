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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int total = 0;
        int deepest = 0;
        function<void(TreeNode*,int)> setValue = [&](TreeNode* node,int lvl)->void{
            if(!node) return;

            if(deepest < lvl){
                total = 1;
                deepest = lvl;
            }
            else if(deepest == lvl){
                total++;
            }

            setValue(node->left,lvl + 1);
            setValue(node->right,lvl + 1);
        };
        setValue(root,0);

        TreeNode* res = nullptr;
        function<int(TreeNode*,int)> solve = [&](TreeNode* node,int lvl)->int{
            if(!node) return 0;

            int cnt = 0;
            if(lvl == deepest){
                cnt++;
            }
            cnt += solve(node->left,lvl + 1) + solve(node->right,lvl + 1);

            if(cnt == total && res == nullptr){
                res = node;
            }
            return cnt;
        };

        solve(root,0);
        return res;
    }
};