/* Leetcode - 23
Companies - VMWare Amazon Uber Google Twitter Linkedin Airbnb Facebook Microsoft IXL
Approach - Merge Sort
TC - O(logk * k * n)
k = total no. of lists, n = avg len of every LL
Why ??
because merge in higher layer has more nodes
the lists are longer than lists in bottoms but no. of operation of merge is same in every level(which is k*n)
and log(k) comes from "partitionMerge" function, we will have log(k) levels and on each level we do a merge.
*/
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val <= l2->val) {
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionMerge(int start, int end, vector<ListNode*> list) {
        if(start == end) {
            return list[start];
        }
        if(start > end) return NULL;
        int mid = start + (end - start) / 2;
        ListNode* l1 = partitionMerge(start, mid, list);
        ListNode* l2 = partitionMerge(mid + 1, end, list);

        return mergeTwoSortedLists(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;

        return partitionMerge(0, n-1, lists);
    }
};
