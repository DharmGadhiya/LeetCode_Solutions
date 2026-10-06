/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *t1 = head, *t2 = head, *t3 = head;
        if (head == nullptr) {
            return nullptr;
        }
        do {
            t1 = t1->next;
            if (t2->next) {
                t2 = t2->next->next;
            } else {
                return nullptr;
            }
        } while (t2 != nullptr && t1 != t2);

        while (t2 != nullptr && t2 != t3) {
            t2 = t2->next;
            t3 = t3->next;
        }
        return t2;
    }
};