class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        while (l1 != nullptr) {
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
        return dummy.next;
    }
};