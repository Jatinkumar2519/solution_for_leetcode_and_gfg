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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> map;
        unordered_set<int> childs;
        for(auto& desc : descriptions){
            int par = desc[0];
            int child = desc[1];
            int isleft = desc[2];

            childs.insert(child);

            if(map.find(par) == map.end()){
                map[par] = new TreeNode(par);
            }

            if(map.find(child) == map.end()){
                map[child] = new TreeNode(child);
            }

            if(isleft){
                map[par]->left = map[child];
            }
            else{
                map[par]->right = map[child];
            }
        }
        
        for(auto& desc : descriptions){
            if(childs.find(desc[0]) == childs.end()) return map[desc[0]];
        }

        return nullptr;
    }
};