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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 1; i<= n; i++){
            fast = fast->next;
        }

        //we have to remove the head of the list
        if(!fast){
            head = head->next;
            return head;
        }

        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        return head;

    }
};