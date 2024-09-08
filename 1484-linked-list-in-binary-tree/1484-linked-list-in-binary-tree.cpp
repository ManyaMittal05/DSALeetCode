/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool traversal(ListNode* head, ListNode* curr, TreeNode* root){
        if(!curr) return true; //successfully matched list
        if(!root) return false; //reached the end of the tree without matching

        if(curr->val == root->val){
            curr = curr->next;
        }
        else if(root->val == head->val){
            head = head->next; // start new matching attempt if value matches the head of the list
        }
        else{
            curr = head; // reset the metchong pointer
        }
        return traversal(head, curr, root->left) || traversal(head, curr, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode* temp = head;
        TreeNode* treeTemp = root;

        return traversal(head, head, root);
    }
};