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
    int maxLevelSum(TreeNode* root) {
        int lvl = 0;
        int curr = 1;
        int maxv = INT_MIN;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int k = q.size();

            int sum = 0;

            while(k--){

                auto node = q.front();q.pop();
                sum += node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                
            }

            if(maxv < sum){
                maxv = sum;
                lvl = curr;
            }

            curr++;
        }

        return lvl;
    }
};