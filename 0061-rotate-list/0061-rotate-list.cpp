class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)return head;

        ListNode* tail = head;
        int len = 1;
        while(tail->next){
            len++;
            tail = tail->next;
        }

        k = k%len;
        tail->next = head;

        ListNode* newTail = head;
        for(int i=1 ; i< len-k; i++){
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;;
        newTail->next = nullptr;

        return newHead;
    }
};