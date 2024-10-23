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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;

        queue<TreeNode*> q;
        q.push(root);
        mp[root] = root->val;

        vector<vector<TreeNode*>> bfs;
        vector<int> levelSum;

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;
            int sum = 0;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                level.push_back(node);
                if(node->left){
                    mp[node->left] = node->left->val + ((node->right) ? node->right->val : 0);
                    q.push(node->left);
                }
                if(node->right){
                    mp[node->right] = node->right->val + ((node->left) ? node->left->val : 0);
                    q.push(node->right);
                }
            }
            levelSum.push_back(sum);
            bfs.push_back(level);
        }

        vector<int> newTreeVals;
        for(int i = 0; i < bfs.size(); i++){
            for(auto node : bfs[i]){   
                newTreeVals.push_back(levelSum[i] - mp[node]);
            }
        }

        q.push(root);
        int i = 0;
        while(!q.empty()){
            TreeNode* node = q.front();
            node->val = newTreeVals[i++];
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return root;
    }
};