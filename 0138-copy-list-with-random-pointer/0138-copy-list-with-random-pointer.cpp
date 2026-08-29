class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;

        unordered_map<Node*, Node*>copy;

        Node* curr = head;
        while(curr){
            copy[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            copy[curr]->next= curr->next ? copy[curr->next] : nullptr;
            copy[curr]->random = curr->random ? copy[curr->random]: nullptr;
            curr = curr->next;
        }
        return copy[head];
    }   
};