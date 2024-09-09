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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int> (n,-1));

        int top = 0, bottom = m-1, left = 0, right = n-1;

        ListNode* temp = head;

        while(temp){
            for(int i = left; temp != NULL && i <= right; i++){
                matrix[top][i] = temp->val;
                temp = temp->next;
            }
            top++;

            for(int j = top; temp != NULL && j <= bottom; j++){
                matrix[j][right] = temp->val;
                temp = temp->next;
            }
            right--;

            for(int i = right; temp != NULL && i >= left; i--){
                matrix[bottom][i] = temp->val;
                temp = temp->next;
            }
            bottom--;

            for(int j = bottom; temp != NULL && j >= top; j--){
                matrix[j][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }

        return matrix;
    }
};