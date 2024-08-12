package org.problems;

// Alternate solution
// Try using two pointers to remove the nth node in one pass!!
// https://medium.com/@eric.christopher.ness/leetcode-19-remove-nth-node-from-end-of-list-5812ddabfa87
class RemoveNthNodeFromListEnd {
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