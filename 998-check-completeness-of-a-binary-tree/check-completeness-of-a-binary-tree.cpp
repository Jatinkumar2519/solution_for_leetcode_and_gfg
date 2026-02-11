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
    bool isCompleteTree(TreeNode* root) {
        // queue<TreeNode*> q;
        // q.push(root);

        // bool flag = false;
        // while(!q.empty()){
        //     auto node = q.front();q.pop();

        //     if(node->left){
        //         if(flag) return false;
        //         else{
        //             q.push(node->left);
        //         }
        //     }
        //     else{
        //         flag = true;
        //     }
        //     if(node->right){
        //         if(flag) return false;
        //         else{
        //             q.push(node->right);
        //         }
        //     }
        //     else{
        //         flag = true;
        //     }
        // }

        // return true;

        function<int(TreeNode*)> countNode = [&](TreeNode* node)->int{
            if(!node) return 0;

            return countNode(node->left) + countNode(node->right) + 1;
        };

        int total = countNode(root);

        function<bool(TreeNode*,int)> solve = [&](TreeNode* node,int indx)->bool{
            if(!node) return true;

            if(indx > total) return false;

            return solve(node->left,indx * 2) && solve(node->right,indx * 2 + 1);
        };

        return solve(root,1);
    }
};