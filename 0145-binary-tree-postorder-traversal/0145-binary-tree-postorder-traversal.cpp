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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;

        stack<TreeNode*> st1;
        st1.push(root);

        stack<TreeNode*> st2;

        while(!st1.empty()){
            TreeNode* node = st1.top();
            st2.push(node);
            st1.pop();

            if(node->left != NULL){
                st1.push(node->left);
            }

            if(node->right != NULL){
                st1.push(node->right);
            }
        }

        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};