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

    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        head->next = NULL;
        front->next = head;
        return newHead;
    }

    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead;

        //in case of even, fast = NULL, and slow will be at the head of the second half of the list
        if(!fast){
            newHead = reverse(slow);
        }
        //in case of odd, fast->next = NULL and slow will be at the mid index which we dont need to compare, hence slow->next
        else{
            newHead = reverse(slow->next);
        }

        ListNode* secondHalf = newHead;
        ListNode* firstHalf = head;

        //coz in case of odd nodes, secondhalf list will be shorter by one node
        while(secondHalf){
            if(firstHalf->val != secondHalf->val){
                return false;
            } 
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};