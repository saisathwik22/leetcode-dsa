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

// Approach 1 - (2 Pass)
// TC - O(n) SC - O(1)
class Solution {
public:
    int travelFront(ListNode* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int L = travelFront(head);
        if(n == L) {
            ListNode* temp = head->next;
            delete(head);
            return temp;
        }
        int travel_front = L - n;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(travel_front--) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete(temp);
        return head;
    }
};

// Approach 2 - One Pass
// TC - O(n) SC - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=1; i<=n; i++) {
            fast = fast -> next;
        }
        if(fast == NULL) {
            return head->next;
        }
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete(temp);
        return head;
    }
};
