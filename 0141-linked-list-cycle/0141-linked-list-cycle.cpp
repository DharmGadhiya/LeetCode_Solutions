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
    bool hasCycle(ListNode* h) {
        if(h == nullptr || h->next == nullptr){
            return false;
        }

        ListNode *t1 = h, *t2 = h;
        while (t1 && t2) {
            
         
            t1 = t1->next;
            if (t2->next) {
                t2 = t2->next->next;
            } else {
                return false;
            }
               if (t1 == t2) {
                return true;
            }
        }
        return false;
    }
};