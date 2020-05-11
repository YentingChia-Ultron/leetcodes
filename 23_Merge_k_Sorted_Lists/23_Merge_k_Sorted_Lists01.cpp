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
        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        ListNode* res = lists[0];
        for(int i = 1; i < lists.size(); i++)
            res = mergeTwoLists(res, lists[i]);
        return res;
    }
private:
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
