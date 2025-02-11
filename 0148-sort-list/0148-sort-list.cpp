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
    ListNode* solve(ListNode* list1, ListNode* list2) {
        if (list1->next == nullptr) {
            list1->next = list2;
            return list1;
        }
        ListNode* curr1 = list1;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = list2;

        while (next1 != nullptr && curr2 != nullptr) {
            if (curr1->val <= curr2->val && next1->val >= curr2->val) {
                curr1->next = curr2;
                ListNode* next2 = curr2->next;
                curr2->next = next1;
                curr1 = curr2;
                curr2 = next2;
            } else {
                curr1 = next1;
                next1 = next1->next;
                if (next1 == nullptr) {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val < list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* middle = middleNode(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;
        
        return merge(sortList(leftHead), sortList(rightHead));
    }
};
