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
    ListNode* middleNode(ListNode* head) {
            ListNode *hare, *tortoise;
            hare=tortoise=head;
    //hare move by 2 step next
    //tortoise move by 1 step next
    while(hare && hare->next){
        hare=hare->next->next;
        tortoise=tortoise->next;
    }

    return tortoise;
            
    }
};