
using namespace std;

/*
 Struct ListNode is in-built in the solution file on leetcode.com.
 When running the code on the website, do not include this struct.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    
public:
    ListNode* partition(ListNode* head, int partionValue) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newHeadLessThan = new ListNode();
        ListNode* lessThan = newHeadLessThan;

        ListNode* newHeadGreaterThanOrEqualTo = new ListNode();
        ListNode* greaterThanOrEqualTo = newHeadGreaterThanOrEqualTo;

        ListNode* current = head;

        while (current != nullptr) {
            if (current->val < partionValue) {
                lessThan->next = current;
                lessThan = lessThan->next;
            } else {
                greaterThanOrEqualTo->next = current;
                greaterThanOrEqualTo = greaterThanOrEqualTo->next;
            }
            current = current->next;
        }

        greaterThanOrEqualTo->next = nullptr;
        lessThan->next = newHeadGreaterThanOrEqualTo->next;

        return newHeadLessThan->next;
    }
};
