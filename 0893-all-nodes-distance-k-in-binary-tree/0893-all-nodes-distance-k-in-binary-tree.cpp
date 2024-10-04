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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        parent_track[root] = NULL;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;

        unordered_map<TreeNode*, TreeNode*> parent_track;
        //identify parent for each node
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int currDist = 0;

        while(!q.empty()){
            int size = q.size();
            if(currDist == k) break;
            currDist++;

            for(int i = 1; i<=size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                //check for left child
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                //check for the right child
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                //check for the parent of the current node
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};