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

        //put the head of all the k lists into the minHeap
        for(int i = 0; i<k; i++){
            if(lists[i] != NULL)
                minHeap.push(lists[i]);
        }

        //make a new answer list that will store the result of the merged lists
        //store the head of the linked list as 0
        ListNode* ans = new ListNode();
        ListNode* tmp = ans;
        while(!minHeap.empty()){
            //extract the top node of the list and insert it int the ans list
            ListNode* node = minHeap.top();
            tmp->next = node;
            tmp = tmp->next;

            //now move the node to next node of the list whose element is used
            node = node->next;

            //pop the top node of the minHeap
            minHeap.pop();

            //if node is not null then insert it into the list
            if(node != NULL){
                minHeap.push(node);
            }
        }
        return ans->next;
    }
};