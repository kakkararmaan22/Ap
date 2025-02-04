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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current != NULL) {
            bool isDuplicate = false;

            while (current->next != NULL && current->val == current->next->val) {
                isDuplicate = true;
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }

            if (isDuplicate) {
                ListNode* temp = current;
                prev->next = current->next;
                current = current->next;
                delete temp;
            } else {
                prev = current;
                current = current->next;
            }
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};