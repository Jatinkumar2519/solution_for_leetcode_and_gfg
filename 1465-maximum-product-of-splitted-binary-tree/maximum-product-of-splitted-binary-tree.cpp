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
    int maxProduct(TreeNode* root) {
        unordered_map<TreeNode*,int> map;
        int mod = 1e9 + 7;

        function<int(TreeNode*)> getReady = [&](TreeNode* node)->int{
            if(!node) return 0;
            int sum = node->val;
            sum = (sum + getReady(node->left));
            sum = (sum + getReady(node->right));
            map[node] = sum;
            return sum;
        };

        int total = getReady(root);

        long long maxv = 0;
        function<void(TreeNode* ,TreeNode* )> solve = [&](TreeNode* node,TreeNode* par)->void{
            if(!node) return;
            if(par){
                maxv = max(maxv,map[node] * 1LL * (total - map[node]));
            }

            solve(node->left,node);
            solve(node->right,node);
        };
        solve(root,nullptr);

        return maxv % mod;
    }
};