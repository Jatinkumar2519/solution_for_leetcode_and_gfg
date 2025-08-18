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
    pair<int,int> solve(TreeNode* root,int& maxv){
        if(!root) return {0,0};
        pair<int,int> left,right,node;
        left = solve(root->left,maxv);
        right = solve(root->right,maxv);
        int size = 1;
        node = {root->val,1};
        if(left.first == node.first){
            node.second += left.second;
            size += left.second;
        }
        if(right.first == node.first){
            node.second = max(node.second,1 + right.second);
            size += right.second;
        }
        maxv = max(maxv,size);
        return node;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxv = 1;
        solve(root,maxv);
        return maxv - 1;
    }
};