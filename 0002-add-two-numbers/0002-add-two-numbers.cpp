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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        int carry = 0;
        while(head1 && head2){
            ListNode* sumNode = new ListNode(head1->val + head2->val + carry);
            if(sumNode->val < 10){
                temp->next = sumNode;
                temp = temp->next;
                carry = 0;
            }
            else{
                carry = 1;
                int val = sumNode->val % 10;
                sumNode->val = val;
                temp->next = sumNode;
                temp = temp->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        while(head1){
            if(carry == 0){
                temp->next = head1;
                return ans->next; 
            }
            ListNode* sumNode = new ListNode(head1->val + carry);
            if(sumNode->val <= 9){
                head1->val++;
                temp->next = head1;
                return ans->next;
            }
            else{
                sumNode->val = sumNode->val % 10;
                carry = 1;
                temp->next = sumNode;
                temp = temp->next; 
            }
            head1 = head1->next;
        }

        while(head2){
            if(carry == 0){
                temp->next = head2;
                return ans->next; 
            }
            ListNode* sumNode = new ListNode(head2->val + carry);
            if(sumNode->val <= 9){
                head2->val++;
                temp->next = head2;
                return ans->next;
            }
            else{
                sumNode->val = sumNode->val % 10;
                carry = 1;
                temp->next = sumNode;
                temp = temp->next; 
            }
            head2 = head2->next;
        }

        if(carry == 1){
            ListNode* newNode = new ListNode(1);
            temp->next = newNode;
        }
        return ans->next;
    }
};