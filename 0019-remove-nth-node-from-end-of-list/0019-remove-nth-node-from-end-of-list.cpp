class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prevHead = new ListNode(0);
        prevHead->next = head;
        
        ListNode* fast = prevHead;
        ListNode* slow = prevHead;
        
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;  
        
        delete nodeToRemove;
  
        ListNode* newHead = prevHead->next;
        delete prevHead;  
        return newHead;
    }
};