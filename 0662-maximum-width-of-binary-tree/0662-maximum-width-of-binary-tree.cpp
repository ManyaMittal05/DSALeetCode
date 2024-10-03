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
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if(!root) return maxWidth;

        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            int minIndAtLevel = q.front().second;
            int first, last;
            
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front().first;
                long currInd = q.front().second - minIndAtLevel;
                q.pop();
                if(i == 0) first = currInd;
                if(i == size-1) last = currInd;
                if(node->left)  
                    q.push({node->left, 2 * currInd + 1});
                if(node->right)
                    q.push({node->right, 2 * currInd + 2});
            }

            maxWidth = max(maxWidth, last - first + 1);
        }
        return maxWidth;
    }
};