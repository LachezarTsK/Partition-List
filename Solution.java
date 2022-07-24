
class Solution {

    public ListNode partition(ListNode head, int partionValue) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHeadLessThan = new ListNode();
        ListNode lessThan = newHeadLessThan;

        ListNode newHeadGreaterThanOrEqualTo = new ListNode();
        ListNode greaterThanOrEqualTo = newHeadGreaterThanOrEqualTo;

        ListNode current = head;

        while (current != null) {
            if (current.val < partionValue) {
                lessThan.next = current;
                lessThan = lessThan.next;
            } else {
                greaterThanOrEqualTo.next = current;
                greaterThanOrEqualTo = greaterThanOrEqualTo.next;
            }
            current = current.next;
        }

        greaterThanOrEqualTo.next = null;
        lessThan.next = newHeadGreaterThanOrEqualTo.next;

        return newHeadLessThan.next;
    }
}

/*
Class ListNode is in-built in the solution file on leetcode.com. 
When running the code on the website, do not include this class.
 */
class ListNode {

    int val;
    ListNode next;

    ListNode() {}

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
