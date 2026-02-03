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
    using ll = long long;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<ll,int> map;
        map[0] = 1;
        
        int count = 0;
        function<void(TreeNode*,ll)> solve = [&](TreeNode* node,ll sum)->void{
            if(!node) return;
            
            sum += node->val;

            count += map[sum - targetSum];
            map[sum]++;

            solve(node->left,sum);
            solve(node->right,sum);

            map[sum]--;
        };

        solve(root,0);
        return count;
    }
};