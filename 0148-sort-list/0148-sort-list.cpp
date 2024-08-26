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
    ListNode* findMiddle(ListNode* head){
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* mergedLists(ListNode* list1, ListNode* list2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                temp= list1;
                list1 = list1->next;
            }

            else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if(list1) temp->next = list1;
        else temp->next = list2;
        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* middleNode = findMiddle(head);
        ListNode* left = head;
        ListNode* right = middleNode->next;
        middleNode->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return mergedLists(left, right);
    }
};