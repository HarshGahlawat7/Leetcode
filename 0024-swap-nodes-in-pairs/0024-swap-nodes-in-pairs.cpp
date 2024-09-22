class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* prevHead = new ListNode(0);
        prevHead->next = head;
        
        ListNode* prev = prevHead;

        while (prev->next && prev->next->next) {
         
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        ListNode* newHead = prevHead->next;
        delete prevHead; 
        return newHead;
    }
};
