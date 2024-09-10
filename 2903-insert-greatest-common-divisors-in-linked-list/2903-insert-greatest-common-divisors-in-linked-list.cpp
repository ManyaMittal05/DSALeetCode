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
    int findGCD(int a, int b){
        int range = min(a, b);
        int gcd = 1;

        for(int i = 1; i <= range; i++){
            if(a % i == 0 && b % i == 0)
                gcd = i;
        }
        return gcd;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* temp = head;

        while(temp && temp->next){
            int val1 = temp->val;
            int val2 = temp->next->val;
            int gcd = findGCD(val1, val2);

            ListNode* newNode = new ListNode(gcd);

            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        return head;
    }
};