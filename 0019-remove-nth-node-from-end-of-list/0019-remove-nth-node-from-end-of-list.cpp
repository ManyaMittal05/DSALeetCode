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
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;

        head = reverseList(head);

        if(n == 1){
            head = head->next;
            head = reverseList(head);
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        while(n != 1){
            prev = temp;
            temp = temp->next;
            n--;
        }

        prev->next = temp->next;
        delete temp;

        return reverseList(head);
    }
};