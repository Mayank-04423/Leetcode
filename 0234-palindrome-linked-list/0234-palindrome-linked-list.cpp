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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head , *fast = head ,*prev = nullptr;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
       
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        //comparison
        while(prev){
            if(head->val != prev->val) return false;
            head= head->next;
            prev = prev ->next;
        }    
        return true;
    }
};