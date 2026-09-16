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
    ListNode *detectCycle(ListNode *head) {
         if (!head || !head->next) {
            return nullptr;
        }

        ListNode* s = head;
        ListNode* f = head;
        ListNode* m = nullptr;

        while (f && f->next) {

            s = s->next;
            f = f->next->next;

            if (s == f) {
                m = s;
                break;
            }
        }

        if (!m) {
            return nullptr;
        }

        ListNode* t = head;

        while (t != m) {
            t = t->next;
            m = m->next;
        }

        return t;
    }
};