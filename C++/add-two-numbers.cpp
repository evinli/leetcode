// Time: O(max(m, n)) where m = # of nodes in l1 and n = # of notes in l2
// Space: O(max(m, n) + 1)
// Helpful links:
    // https://www.geeksforgeeks.org/different-ways-to-instantiate-an-object-in-c-with-examples/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // pointer to the dummy head of linked list
        ListNode* curr = dummyHead; // set current position to the dummy head
        int carryOver = 0;
        
        while (l1 != nullptr || l2 != nullptr || carryOver != 0) {
            int sum = 0;
            if (l1 != nullptr) sum += l1->val;
            if (l2 != nullptr) sum += l2->val;
            sum += carryOver;
            
            // compute carry over and add sum to a new node in the linked list            
            carryOver = sum / 10; 
            curr->next = new ListNode(sum % 10);
            
            // set current position to next node in linked list and advance l1 and l2
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;   
        }
        return dummyHead->next; // skip dummy head and return linked list
    }
};