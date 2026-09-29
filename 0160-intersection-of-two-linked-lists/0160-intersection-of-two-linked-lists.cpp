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
    ListNode* getIntersectionNode(ListNode* ha, ListNode* hb) {
        ListNode *t1 = ha, *t2 = hb;
        while (t1 != t2) {
            if (t1 == nullptr) {
                t1 = hb;
            } else {
                t1 = t1->next;
            }

            if (t2 == nullptr) {
                t2 = ha;
            } else {
                t2 = t2->next;
            }
        }
        return t1;
    }
};