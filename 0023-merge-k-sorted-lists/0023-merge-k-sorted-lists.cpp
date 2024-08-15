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
class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        int k = lists.size();
        for(int i = 0; i<k; i++){
            if(lists[i] != NULL)
                minHeap.push(lists[i]);
        }

        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            tmp->next = node;
            tmp = tmp->next;
            node = node->next;

            minHeap.pop();

            if(node != NULL){
                minHeap.push(node);
            }
        }
        return ans->next;
    }
};