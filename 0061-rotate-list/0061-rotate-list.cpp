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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Compute the length and find the actual tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // 2. Adjust k
        k = k % n;
        if (k == 0) return head;

        // 3. Link tail to head to form a circle
        tail->next = head;

        // 4. Find the new tail: it's (n - k - 1) steps from the start
        ListNode* new_tail = head;
        for (int i = 0; i < n - k - 1; i++) {
            new_tail = new_tail->next;
        }

        // 5. Break the circle
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;

        return new_head;
    }
};