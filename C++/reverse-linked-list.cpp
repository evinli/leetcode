//https://medium.com/outco/reversing-a-linked-list-easy-as-1-2-3-560fbffe2088

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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // move next pointer to next node
            curr->next = previous; // set arrow to point from current node to previous node
            previous = curr; // move previous pointer to current node
            curr = next; // move current pointer to next node
        }

        return previous; // return head of reversed list
    }
};

