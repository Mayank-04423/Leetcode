class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return nullptr;

        ListNode* temp = head;
        for(int i=0; i<k; i++){
            if(!temp)return head;
            temp = temp->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while(curr && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        head->next = reverseKGroup(curr,k);

        return prev;

    }
};