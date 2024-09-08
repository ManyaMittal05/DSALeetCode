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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        int extra = count % k;
        int partSize = count / k;

        temp = head;
        vector<ListNode*> ans;
        while(temp){
            int size = partSize;
            ans.push_back(temp);
            while(temp && size > 1){
                temp = temp->next;
                size--;
            }

            if(temp && extra > 0 && size != 0){
                temp = temp->next;
                extra--;
            }

            ListNode* t1 = temp;
            if(temp) temp = temp->next;
            if(t1) t1->next = NULL;
        }

        while(ans.size() != k){
            ans.push_back(nullptr);
        }
        return ans;
    }
};