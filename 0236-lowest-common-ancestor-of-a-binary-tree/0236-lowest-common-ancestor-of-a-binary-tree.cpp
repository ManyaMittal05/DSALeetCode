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
    bool findRootToNodePath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        if(!root) return false;
        
        path.push_back(root);

        if(root == node)
            return true;

        if(findRootToNodePath(root->left, node, path) ||
                findRootToNodePath(root->right, node, path))
                return true;
        
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        findRootToNodePath(root, p, pPath);
        findRootToNodePath(root, q, qPath);

        TreeNode* ansNode;
        int range = min(pPath.size(), qPath.size());
        for(int i = 0; i<range; i++){
            if(pPath[i] == qPath[i])
                ansNode = pPath[i];
        }
        return ansNode;
    }
};