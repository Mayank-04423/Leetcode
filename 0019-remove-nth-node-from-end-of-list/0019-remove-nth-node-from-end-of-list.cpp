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

        ListNode* demo = new ListNode(0);
        demo->next = head;

        ListNode* slow = demo;
        ListNode* fast = demo;

        //moving fast n spaces ahead of slow 
        for(int i = 0 ; i<n ; i++){
            fast = fast->next;
        }

        while(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;


        return demo->next;
    }
};