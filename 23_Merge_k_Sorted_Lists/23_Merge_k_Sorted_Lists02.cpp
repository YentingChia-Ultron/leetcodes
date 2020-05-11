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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeLists(lists, 0, lists.size() - 1);
    }
private:
    ListNode* mergeLists(vector<ListNode*>& lists, int left, int right)
    {
        if(left > right) return nullptr;
        if(left == right) return lists[left];
        if(left + 1 == right) return mergeTwoLists(lists[left], lists[right]);
        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeLists(lists, left, mid);
        ListNode* l2 = mergeLists(lists, mid + 1, right);
        return mergeTwoLists(l1, l2);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode res(0);
        ListNode* tail = &res;
        while(l1 && l2)
        {
            if(l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        tail->next = l1? l1 : l2;
        return res.next;
    }
};
