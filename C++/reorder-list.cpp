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

// Using pointers, tortoise and hare method
class Solution {
public:
    void reorderList(ListNode* head) {
        // Edge cases
        if (head == nullptr && head->next == nullptr && head->next->next == nullptr) return;

        // Tortoise and hare method for finding middle of linked list
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // Reverse second half of linked list and truncate first half
        ListNode* head2 = reverse(slow->next);
        slow->next = nullptr;

        // Create a new dummy linked list
        ListNode* dummyHead = new ListNode();
        ListNode* curr = dummyHead;

        // Insert nodes from first and second half (in alternate order)
        while (head != nullptr || head2 != nullptr) {
            if (head != nullptr) {
                curr->next = head;
                curr = curr->next;
                head = head->next;
            }

            if (head2 != nullptr) {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }

        // Set original linked list to dummy list
        head = dummyHead->next;
    }

    // Method to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Using a stack
