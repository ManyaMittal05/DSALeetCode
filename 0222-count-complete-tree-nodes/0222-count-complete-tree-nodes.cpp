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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count = 0; 

        queue<TreeNode*> q;
        q.push(root);
        count++;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                count++;
            } else break;
            if(node->right){
                q.push(node->right);
                count++;
            } else break;
        }
        return count;
    }
};