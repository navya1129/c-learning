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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *aft = curr->next;
        while(curr->next != NULL){
            curr->next = prev;
            prev = curr;
            curr = aft;
            aft = aft->next;
        }
        curr->next = prev;
        prev = curr;
        return prev;
    }
};