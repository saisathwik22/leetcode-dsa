// Approach - BRUTE
// TC - O(n*2*logn) SC - O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while(temp != NULL) {
            if(nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            nodeMap[temp] = 1;

            temp = temp->next;
        }
        return false;
    }
};

// Tortoise and Hare Algorithm
// Approach - optimal
// TC - O(n) SC - O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }
        return false;
    }
};
