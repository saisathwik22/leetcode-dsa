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

// Approach 1 - without Stack
// TC - O(n)
// SC - Auxillary space O(1)
// SC - O(n) -> System Recursion Stack Space
class Solution {
public:

    ListNode* reverseLL(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev = reverseLL(slow);
        ListNode* curr = head;
        while(rev->next != NULL) {
            ListNode* tempCurr = curr->next;
            curr->next = rev;
            ListNode* tempRev = rev->next;
            rev->next = tempCurr;

            curr = tempCurr;
            rev = tempRev;
        }
    }
};

// Approach 2 - with Stack
// TC -> O(n) SC -> O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(curr) {
            st.push(curr);
            curr = curr->next;
        }
        int k = st.size() / 2;
        curr = head;
        while(k--) {
            ListNode* topNode = st.top();
            st.pop();
            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;
            curr = temp;
        }
        curr -> next = NULL;
    }
};

// Approach 3 - using Recursion - while rec is rewinding
// TC - O(n)
// SC - O(1) * Auxillary space
// SC - O(n) -> System recursion stack space.
class Solution {
public:
    ListNode* curr;
    void solve(ListNode* head) {
        if(head == NULL) {
            return;
        }
        solve(head->next);
        ListNode* temp = curr->next;
        if(curr->next == NULL) {
            return;
        } else if(head == curr) {
            head -> next = NULL;
            return;
        }
        curr->next = head;
        head->next = (temp == head) ? NULL : temp;
        curr = temp;
    }
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};
