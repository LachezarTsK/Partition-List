
/*
 Function ListNode is in-built in the solution file on leetcode.com. 
 When running the code on the website, do not include this function.
 */
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

/**
 * @param {ListNode} head
 * @param {number} partionValue
 * @return {ListNode}
 */
var partition = function (head, partionValue) {
    if (head === null || head.next === null) {
        return head;
    }

    let newHeadLessThan = new ListNode();
    let lessThan = newHeadLessThan;

    let newHeadGreaterThanOrEqualTo = new ListNode();
    let greaterThanOrEqualTo = newHeadGreaterThanOrEqualTo;

    let current = head;

    while (current !== null) {
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
};
