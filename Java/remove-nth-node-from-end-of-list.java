/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = head;

        // Count number of nodes in list
        int len = 0;
        while (curr != null) {
            len++;
            curr = curr.next;
        }

        // Remove nth node from end of list
        ListNode curr_pos;

        // Case 1: Nth node is later in list
        if (len - n > 0) {
            // Start list from head
            curr_pos = head;
            for (int i = 1; i < len - n; i++) curr_pos = curr_pos.next;
            // Jump over nth node
            if (curr_pos.next != null) curr_pos.next = curr_pos.next.next;
            return head;
        }
        // Case 2: Nth node is the head of the list
        else if (len - n == 0) {
            // Start list second node in list (aka. remove head)
            head = head.next;
            curr_pos = head;
            return head;
        }

        return head;
    }
}

// Alternate solution
 // Try using two pointers to remove the nth node in one pass!!
 // https://medium.com/@eric.christopher.ness/leetcode-19-remove-nth-node-from-end-of-list-5812ddabfa87
 class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode(0, head);
        ListNode first = dummyHead;
        ListNode second = dummyHead;

        for (int i = 0; i <= n; i++) {
            second = second.next;
        }

        while (second != null) {
            second = second.next;
            first = first.next;
        }

        first.next = first.next.next;
        return dummyHead.next;

    }
}