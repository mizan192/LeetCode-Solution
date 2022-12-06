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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if(head==NULL) return NULL;
            ListNode* even = head->next;
            while(even && even->next)
            {
                ListNode* node = even->next;
                even->next = node->next;
                even = even->next;
                node->next = odd->next;
                odd->next = node;
                odd = node;
            }
            return head;
    }
};