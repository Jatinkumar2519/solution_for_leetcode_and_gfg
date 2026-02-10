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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        function<void(TreeNode*)> dfs = [&](TreeNode* node)->void{
            if(!node) return;

            dfs(node->left);
            arr.push_back(node->val);
            dfs(node->right);
        };
        dfs(root);

        function<TreeNode*(int ,int)> solve = [&](int i,int j)->TreeNode*{
            if(i > j) return nullptr;
            
            int mid = (i + j)/2;

            TreeNode* node = new TreeNode(arr[mid]);
            node->left = solve(i,mid - 1);
            node->right = solve(mid + 1,j);

            return node;
        };

        int n = arr.size();
        return solve(0,n - 1);
    }
};