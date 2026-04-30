/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        map<ListNode*,ListNode*> m;
        ListNode* temp = head;
        while(temp->next != NULL){
            if(m.find(temp) != m.end() && m[temp] == temp->next) return true;
            else if(m.find(temp) == m.end()) m[temp] = temp->next;
            temp = temp->next;
        }
        return false;
    }
};